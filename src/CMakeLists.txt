# CMakeList.txt : CMake project for kv_store, include source and define
# project specific logic here.

cmake_minimum_required (VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add source to this project's executable.
add_library (kv_store_lib 
"kv_store_engine.cc" 
"file_storage.cc" 
"cli_interface.cc")

add_executable (kv_store "main.cc" )

target_link_libraries(kv_store
    PRIVATE
    kv_store_lib
)

add_custom_command(
    TARGET kv_store POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_SOURCE_DIR}/data"
            "$<TARGET_FILE_DIR:kv_store>/data"
)

# target_include_directories(kv_store PRIVATE "${CMAKE_SOURCE_DIR}/include")
