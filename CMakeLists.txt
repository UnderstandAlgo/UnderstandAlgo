# Minimum CMake version
cmake_minimum_required(VERSION 3.27.8)

project(UnderstandAlgo)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED True)

# Name of the executable and the source files
add_executable(UnderstandAlgo main.cpp Algorithms/Searching/DFS/DFS.cpp
        Structures/ADT/Graph.hpp
        Structures/ADT/Graph.tpp)


# gtest configuration from https://programmador.com/posts/using-googletest-with-cmake/
include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1)
FetchContent_MakeAvailable(googletest)

option(BUILD_TESTS "Build Unit Tests" OFF)
if(BUILD_TESTS)
    enable_testing()
    include(GoogleTest)
    add_subdirectory(tests)
endif()

