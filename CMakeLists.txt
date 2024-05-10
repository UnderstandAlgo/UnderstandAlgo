cmake_minimum_required(VERSION 3.10)
project(UnderstandAlgo VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify directory where GoogleTest is
add_subdirectory(googletest)

# Include gtest library
include_directories(${gtest_SOURCE_DIR}/include
        ${gtest_SOURCE_DIR})

# Create a library with the source files
add_library(
        UnderstandAlgo
        main.cpp
        Structures/Static/StaticArray.tpp
        Structures/Static/StaticArray.h
)

# Adding the Google_Test_run target
add_executable(
        Google_Test_run
        Tests/StaticArrayTest.cpp
)

# Specify these libraries should be linked to Google_Test_run binary
target_link_libraries(
        Google_Test_run
        UnderstandAlgo
        gtest
        gtest_main
)

# Adding tests subdirectory
add_subdirectory(tests)
