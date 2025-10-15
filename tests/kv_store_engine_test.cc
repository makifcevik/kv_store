#include "kv_store/kv_store_engine.h"

#include <filesystem>
#include <memory>
#include <string>

#include "kv_store/file_storage.h"

#include <gtest/gtest.h>

class KVStoreEngineTest : public ::testing::Test {
 protected:
  std::string test_file = "test_engine_data.txt";

  void TearDown() override {
    if (std::filesystem::exists(test_file))
      std::filesystem::remove(test_file);
  }

  std::unique_ptr<FileStorage> CreateFileStorage() {
    return std::make_unique<FileStorage>(test_file);
  }
};

TEST_F(KVStoreEngineTest, SetAndGet_SetsAndGetsCorrectValue) {
  // Arrange
  KVStoreEngine engine(CreateFileStorage());
  // Act
  engine.Set("key1", "value1");
  auto value = engine.Get("key1");
  // Assert
  ASSERT_TRUE(value.has_value());
  EXPECT_EQ(value.value(), "value1");
}

TEST_F(KVStoreEngineTest, Delete_RemovesExistingKey) {
  // Arrange
  KVStoreEngine engine(CreateFileStorage());
  // Act
  engine.Set("key1", "value1");
  engine.Delete("key1");
  auto value = engine.Get("key1");
  // Assert
  EXPECT_FALSE(engine.Get("key1").has_value());
}

TEST_F(KVStoreEngineTest, Persist_SavesToFile) {
  // Arrange
  KVStoreEngine engine(CreateFileStorage());
  // Act
  engine.Set("key1", "value1");
  engine.Persist();
  // Simulate a new instance loading the data from the file.
  KVStoreEngine new_engine(CreateFileStorage());
  auto loaded = engine.GetAll();
  // Assert
  ASSERT_TRUE(loaded.has_value());
  EXPECT_EQ(loaded->at("key1"), "value1");
}
