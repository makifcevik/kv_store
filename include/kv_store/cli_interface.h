// MIT License

#ifndef KV_STORE_INCLUDE_KV_STORE_CLI_INTERFACE
#define KV_STORE_INCLUDE_KV_STORE_CLI_INTERFACE

#include <iostream>
#include <string>

// CLIInterface class provides a command-line interface for interacting with the
// key-value store.

class CLIInterface {
 public:
  // Provides the main loop to run the CLI interface.
  static void Run();

 private:
  // Used to retrieve user commands.
  static void GetCommand(std::string& command);
  // Processes user commands
  static void ProcessCommand(const std::string& command);
  // Displays all avaliable commands.
  static void Help();
};

#endif  // !KV_STORE_INCLUDE_KV_STORE_CLI_INTERFACE
