# CMakeList.txt : CMake project for kv_store, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (kv_store "main.cpp"  "kv_store_engine.cpp" "file_storage.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.15)
  set_property(TARGET kv_store PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
