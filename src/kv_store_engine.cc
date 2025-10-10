#include "kv_store/kv_store_engine.h"

#include <iostream>

KVStoreEngine::KVStoreEngine(UniqueFileStorage storage)
    : storage_(std::move(storage)) {
  map_ = storage_->Load().value_or(KVMap{});

  std::cout << "Loaded " << map_.size() << " key-value pairs from storage.\n";
}

// Set or update the value for the given key.
void KVStoreEngine::Set(const std::string& key, const std::string& value) {
  map_[key] = value;
}
std::optional<std::string> KVStoreEngine::Get(const std::string& key) const {
  auto it = map_.find(key);
  if (it != map_.end()) {
    return it->second;
  }
  return std::nullopt;
}
std::optional<KVStoreEngine::KVMap> KVStoreEngine::GetAll() const {
  if (map_.empty()) {
    return std::nullopt;
  }
  return map_;
}
bool KVStoreEngine::Delete(const std::string& key) {
  if (map_.find(key) != map_.end()) {
    map_.erase(key);
    return true;
  }
  return false;
}
void KVStoreEngine::Persist() const {
  storage_->Save(map_);
}