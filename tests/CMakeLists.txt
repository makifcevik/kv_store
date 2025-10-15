cmake_minimum_required (VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable (kv_store_tests 
"file_storage_test.cc"
"kv_store_engine_test.cc"
)

target_link_libraries(kv_store_tests
    PRIVATE
    kv_store_lib
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(kv_store_tests)
