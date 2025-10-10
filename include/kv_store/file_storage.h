// MIT License

#ifndef KV_STORE_FILE_STORAGE_H
#define KV_STORE_FILE_STORAGE_H

#include <string>
#include <unordered_map>
#include <optional>

// FileStorage class provides file-based storage for key-value pairs.

class FileStorage {
 public:
  using KVMap = std::unordered_map<std::string, std::string>;

  // Constructor that takes the file path for storage.
  explicit FileStorage(const std::string& filepath);

  // Save the key-value pairs to the file. 
  // Existing content will be overwritten.
  void Save(const KVMap& kv_map) const;
  // Load the key-value pairs from the file. 
  // Returns std::nullopt if the file does not exist.
  std::optional<KVMap> Load() const;

 private:
  std::string filepath_;
};

#endif  // !KV_STORE_FILE_STORAGE_H
