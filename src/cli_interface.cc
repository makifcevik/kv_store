#include "kv_store/cli_interface.h"

#include <iostream>

// Main CLI Loop. Keeps retrieving and processing user input commands.
// Commands are written on command local variable
void CLIInterface::Run() {
  std::cout << "Running CLI Interface...\nType `help` to see the available\n";
  std::string command;
  while (true) {
    GetCommand(command);
    ProcessCommand(command);
  }
}

void CLIInterface::GetCommand(std::string& command) {
  std::cout << "> ";
  std::cin >> command;
}

void CLIInterface::ProcessCommand(const std::string& command) {
  if (command == "help") {
    Help();
  } else if (command == "get") {
    std::cout << "Get command executed.\n";
  } else if (command == "set") {
    std::cout << "Set command executed.\n";
  } else if (command == "delete") {
    std::cout << "Delete command executed.\n";
  } else if (command == "exit") {
    std::cout << "Exiting CLI Interface...\n";
    exit(0);
  } else {
    std::cout
        << "Unknown command. Type `help` to see the available commands.\n";
  }
}

void CLIInterface::Help() {
  std::cout << "Available commands:\n  - help\n  - get\n  - set\n  - delete\n  "
               "- exit\n";
}