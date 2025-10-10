// MIT License

#ifndef KV_STORE_CLI_INTERFACE_H
#define KV_STORE_CLI_INTERFACE_H

#include <memory>
#include <string>

class KVStoreEngine;

// CLIInterface class provides a command-line interface for interacting with the
// key-value store.

class CLIInterface {
 public:
  using UniqueEngine = std::unique_ptr<KVStoreEngine>;

  explicit CLIInterface(UniqueEngine engine) : engine_(std::move(engine)) {}

  // Provides the main loop to run the CLI interface.
  void Run() const;

 private:
  // Used to retrieve user commands.
  void GetCommand(std::string& command) const;
  
  // Dispatches the command to the appropriate handler.
  void ProcessCommand(const std::string& command) const;

  // Handlers for each command
  // Changes are not saved to the file until `persist` command is called.
  void HandleSet(std::stringstream& ss) const;
  void HandleGet(std::stringstream& ss) const;
  void HandleGetAll() const;
  void HandleDelete(std::stringstream& ss) const;
  void HandleExit() const;
  void HandleHelp() const;
  void HandlePersist() const;

  UniqueEngine engine_;
};
#endif  // !KV_STORE_CLI_INTERFACE_H
