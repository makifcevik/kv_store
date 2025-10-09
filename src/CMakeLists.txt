# CMakeList.txt : CMake project for kv_store, include source and define
# project specific logic here.

cmake_minimum_required (VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source to this project's executable.
add_executable (kv_store 
"main.cc"  
"kv_store_engine.cc" 
"file_storage.cc" 
"cli_interface.cc")

# target_include_directories(kv_store PRIVATE "${CMAKE_SOURCE_DIR}/include")
