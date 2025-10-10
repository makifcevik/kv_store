// MIT License

#ifndef KV_STORE_INCLUDE_KV_STORE_KV_STORE_ENGINE
#define KV_STORE_INCLUDE_KV_STORE_KV_STORE_ENGINE

#include <string>
#include <unordered_map>
#include <optional>
#include <memory>
#include "file_storage.h"

//class FileStorage;

// The core business logic layer.
// KVStoreEngine class provides in-memory key-value storage with basic operations.
// It provides public methods to encapsulate business logic.
// Does not persist changes to the file until Persist() is called.

class KVStoreEngine {
 public:
  using KVMap = std::unordered_map<std::string, std::string>;
  using UniqueFileStorage = std::unique_ptr<FileStorage>;

  explicit KVStoreEngine(UniqueFileStorage storage);

  // Does not persist changes to the file until Persist() is called.
  // Set or update the value for the given key. 
  // If you do not want to override existing values, check with Get() first.
  void Set(const std::string& key, const std::string& value);

  std::optional<std::string> Get(const std::string& key) const;
  std::optional<KVMap> GetAll() const;

  // Does not persist changes to the file until Persist() is called.
  // Returns true if the key existed and was deleted, false otherwise.
  bool Delete(const std::string& key);

  // Persist the in-memory key-value pairs to the file.
  void Persist() const;

 private:
  KVMap map_{};
  UniqueFileStorage storage_;
};

#endif  // !KV_STORE_INCLUDE_KV_STORE_KV_STORE_ENGINE
