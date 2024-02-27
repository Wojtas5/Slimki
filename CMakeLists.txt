cmake_minimum_required(VERSION 3.14)
project(Slimki)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_subdirectory(src)
add_subdirectory(tests)

add_executable(Slimki src/main.cpp)

add_subdirectory(external/googletest)
include_directories(external/googletest/include)