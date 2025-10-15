# KV Store

A simple, file-based key-value store implemented in C++ following **Google C++ standards**. This project provides a command-line interface (CLI) for storing, retrieving, and deleting key-value pairs.

## Features

  * **Persistent Storage:** Key-value pairs are stored in a .txt file, ensuring data persistence across sessions.
  * **Command-Line Interface:** Interact with the key-value store through a simple and intuitive CLI.
  * **Core Engine:** A robust key-value store engine which handles the core logic of data management.

## Prerequisites

You can build an run this project with **CMake** provided that you have both **CMake** and a **C++** compiler installed on your system.

## Usage

You can interact with the key-value store using the command-line interface. Here are some example commands:

  * **Set a key-value pair:**

    ```bash
    set mykey myvalue
    ```

  * **Get the value for a key:**

    ```bash
    get mykey
    ```

  * **Delete a key-value pair:**

    ```bash
    delete mykey
    ```

## Project Structure

The project is organized into the following directories:

  * `include/`: Contains the header files for the project.
      * `kv_store/cli_interface.h`: Declares the command-line interface functions.
      * `kv_store/file_storage.h`: Declares the file storage functions.
      * `kv_store/kv_store_engine.h`: Declares the core key-value store engine class.
  * `src/`: Contains the source code files.
      * `cli_interface.cc`: Implements the command-line interface.
      * `file_storage.cc`: Implements the file storage logic.
      * `kv_store_engine.cc`: Implements the core key-value store engine.
      * `main.cc`: The main entry point of the application.
  * `data/`: Contains the data file for the key-value store.
      * `data.txt`: The default file for storing key-value pairs.
  * `tests/`: Contains the tests of the project.

-----

## License

This project is licensed under the MIT License - see the LICENSE.md file for details.
