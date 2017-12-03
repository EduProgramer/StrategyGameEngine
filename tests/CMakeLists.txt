cmake_minimum_required (VERSION 3.6)
project (TestSGE)
add_definitions(-std=c++14)
add_subdirectory (googletest)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/TestSGE)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/TestSGE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/TestSGE)

include_directories("./src")
include_directories("../src")

file(GLOB SOURCE "../src/**")
file(GLOB TESTS "./src/**")

add_executable(TestSGE main.cpp ${SOURCE} ${TESTS})

target_link_libraries(TestSGE gtest)
target_link_libraries(TestSGE gmock)

add_compile_options(-Wall -Wextra -Wpedantic --coverage -O0)
