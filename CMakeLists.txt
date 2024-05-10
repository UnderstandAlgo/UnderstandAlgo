cmake_minimum_required(VERSION 3.10)
project(UnderstandAlgo VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(googletest)

# create a library with the source files
add_library(
        UnderstandAlgo
        main.cpp
        Structures/Static/StaticArray.tpp
        Structures/Static/StaticArray.h
)

target_link_libraries(
        UnderstandAlgo
        gtest
        gtest_main
)

# adding the Google_Test_run target
add_executable(
        Google_Test_run
        Tests/StaticArrayTest.cpp
)

target_link_libraries(
        Google_Test_run
        UnderstandAlgo
)