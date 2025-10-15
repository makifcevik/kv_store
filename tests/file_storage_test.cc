#include "kv_store/file_storage.h"

#include <filesystem>
#include <string>

#include <gtest/gtest.h>

class FileStorageTest : public ::testing::Test {
 protected:
  std::string test_file = "test_data.txt";

  void TearDown() override {
    if (std::filesystem::exists(test_file))
      std::filesystem::remove(test_file);
  }
};

TEST_F(FileStorageTest, SaveAndLoad_ReturnsSavedData) {
  // Arrange
  FileStorage storage(test_file);
  FileStorage::KVMap kv = {{"test_key_1", "test_value_1"},
                           {"test_key_2", "test_value_2"}};
  // Act
  storage.Save(kv);
  auto result = storage.Load();
  // Assert
  ASSERT_TRUE(result.has_value());
  EXPECT_EQ(result->at("test_key_1"), "test_value_1");
  EXPECT_EQ(result->at("test_key_2"), "test_value_2");
}

TEST_F(FileStorageTest, Load_ReturnsNullOptIfFileDoesNotExist) {
  // Arrange
  FileStorage storage("file_that_does_not_exist.txt");
  // Act
  auto result = storage.Load();
  // Assert
  EXPECT_FALSE(result.has_value());
}
