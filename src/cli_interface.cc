#include "kv_store/cli_interface.h"

#include <iostream>
#include <sstream>

#include "kv_store/kv_store_engine.h"

// Main CLI Loop. Keeps retrieving and processing user input commands.
// Commands are written on command local variable
void CLIInterface::Run() const {
  std::cout << "Running CLI Interface...\nType `help` to see the available\n";
  std::string command;
  while (true) {
    GetCommand(command);
    ProcessCommand(command);
  }
}
void CLIInterface::GetCommand(std::string& command) const {
  std::cout << "> ";
  std::getline(std::cin, command);
}
void CLIInterface::ProcessCommand(const std::string& command) const {
  std::string cmd_type;
  std::stringstream ss(command);
  ss >> cmd_type;
  if (cmd_type == "set") {
    HandleSet(ss);
  } else if (cmd_type == "get") {
    HandleGet(ss);
  } else if (cmd_type == "getall") {
    HandleGetAll();
  } else if (cmd_type == "delete") {
    HandleDelete(ss);
  } else if (cmd_type == "help") {
    HandleHelp();
  } else if (cmd_type == "persist") {
    HandlePersist();
  } else if (cmd_type == "exit") {
    HandleExit();
  } else {
    std::cout
        << "Unknown command. Type `help` to see the available commands.\n";
  }
}

void CLIInterface::HandleGetAll() const {
  auto all = engine_->GetAll();
  if (all.has_value()) {
    for (const auto& [key, value] : *all) {
      std::cout << key << ": " << value << "\n";
    }
  } else {
    std::cout << "No key-value pairs found.\n";
  }
}
void CLIInterface::HandleSet(std::stringstream& ss) const {
  std::string key, value;
  ss >> key >> value;
  if (key.empty() || value.empty()) {
    std::cout << "Invalid command format. Usage: set <key> <value>\n";
  } else {
    engine_->Set(key, value);
    std::cout << key << " set to " << value << "\n";
  }
}
void CLIInterface::HandleGet(std::stringstream& ss) const {
  std::string key;
  ss >> key;
  if (key.empty()) {
    std::cout << "Invalid command format. Usage: get <key>\n";
    return;
  } else {
    key =
        engine_->Get(key).has_value() ? *(engine_->Get(key)) : "Key not found.";
    std::cout << key << "\n";
  }
}
void CLIInterface::HandleDelete(std::stringstream& ss) const {
  std::string key;
  ss >> key;
  if (key.empty()) {
    std::cout << "Invalid format. Usage: delete <key>\n";
  } else {
    if (engine_->Delete(key)) {
      std::cout << "Key " << key << " deleted.\n";
    } else {
      std::cout << "Key " << key << " not found.\n";
    }
  }
}
void CLIInterface::HandleExit() const {
  std::cout << "Are you sure you want to exit without persisting? (y/n): ";
  char choice;
  std::cin >> choice;
  if (choice == 'y' || choice == 'Y') {
    std::cout << "Exiting without persisting...\n";
    exit(0);
  } else {
    std::cout << "Exit cancelled. Returning to main menu.\n";
  }
}

void CLIInterface::HandlePersist() const {
  engine_->Persist();
  std::cout << "Data persisted to storage.\n";
}

void CLIInterface::HandleHelp() const {
  std::cout
      << "Available commands:\n"
      << "  - help               : Shows this help message.\n"
      << "  - getall             : Retrieves all key-value pairs.\n"
      << "  - set <key> <value>  : Sets a key with the given value.\n"
      << "  - get <key>          : Retrieves the value for the given key.\n"
      << "  - delete <key>       : Deletes the key-value pair.\n"
      << "  - persist            : Persists the current data to storage.\n"
      << "  - exit               : Exits the application.\n";
}