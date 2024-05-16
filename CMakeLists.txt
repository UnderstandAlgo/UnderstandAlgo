# Minimum CMake version
cmake_minimum_required(VERSION 3.27.8)

project(UnderstandAlgo)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED True)

# Name of the executable and the source files
add_executable(UnderstandAlgo main.cpp Algorithms/Searching/DFS/DFS.cpp)


