cmake_minimum_required(VERSION 3.10)
project(UnderstandAlgo VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(UnderstandAlgo
        main.cpp
        Structures/Static/StaticArray.tpp
        Structures/Static/StaticArray.h)
#add executables here to be tested.