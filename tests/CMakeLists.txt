cmake_minimum_required(VERSION 3.14)
project(SlimkiTest)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

enable_testing()

add_executable(
  slimki_test
  hello_test.cpp
  ../src/huffman.cpp
  ../src/huffman_tree.cpp
  huffman_test.cpp
  huffman_tree_test.cpp
  huffman_tree_utils.cpp
)

target_link_libraries(
  slimki_test
  GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(slimki_test)

add_custom_command(
  TARGET slimki_test
  COMMENT "Run tests"
  POST_BUILD 
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  COMMAND ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> -R "^${UNIT_TEST}$" --output-on-failure
)