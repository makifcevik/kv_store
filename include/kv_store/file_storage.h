#ifndef KV_STORE_INCLUDE_KV_STORE_FILE_STORAGE
#define KV_STORE_INCLUDE_KV_STORE_FILE_STORAGE

#include <string>
#include <unordered_map>

// FileStorage class provides file-based storage for key-value pairs.

class FileStorage {
 public:
  using KVMap = std::unordered_map<std::string, std::string>;

  explicit FileStorage(const std::string& filepath);

  void Save(const KVMap& kv_map);
  KVMap Load();
};

#endif  // !KV_STORE_INCLUDE_KV_STORE_FILE_STORAGE
