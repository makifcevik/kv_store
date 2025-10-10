#include "kv_store/file_storage.h"

#include <fstream>
#include <iostream>

FileStorage::FileStorage(const std::string& filepath) : filepath_(filepath) {}

// key-value pairs are seperated with ":".
// Each key-value pair is stored in a new line.
// Returns std::nullopt if the file does not exist.
std::optional<FileStorage::KVMap> FileStorage::Load() const {
  std::ifstream in(filepath_);
  std::string line;
  KVMap kv_map;
  if (in.is_open()) {
    std::cout << "Loading data from " << filepath_ << "...\n";
    while (std::getline(in, line)) {
      size_t pos = line.find(":");
      if (pos != std::string::npos) {
        std::string key = line.substr(0, pos);
        std::string value = line.substr(pos + 1);
        kv_map[key] = value;
      }
    }
    return kv_map;
  }
  return std::nullopt;
}

// Overwrites existing content.
// key-value pairs are seperated with ":".
// Each key-value pair is stored in a new line.
void FileStorage::Save(const KVMap& kv_map) const {
  std::ofstream out(filepath_, std::ios::trunc);
  if (out.is_open()) {
    for (const auto& [key, value] : kv_map) {
      out << key << ":" << value << "\n";
    }
  }
}