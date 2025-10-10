#include <iostream>

#include "kv_store/cli_interface.h"
#include "kv_store/file_storage.h"
#include "kv_store/kv_store_engine.h"

int main() {
  // Create the engine with FileStorage
  auto engine = std::make_unique<KVStoreEngine>(
      std::make_unique<FileStorage>("data/data.txt"));

  // Create and run the CLI interface
  CLIInterface cli{std::move(engine)};
  cli.Run();

  return 0;
}
