# Minimum CMake version
cmake_minimum_required(VERSION 3.27.8)

project(UnderstandAlgo)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Create a static library
add_library(UnderstandAlgo_lib STATIC
        Algorithms/Searching/DFS/DFS.cpp)

# Main executable
add_executable(UnderstandAlgo main.cpp)
target_link_libraries(UnderstandAlgo PRIVATE UnderstandAlgo_lib)

# GoogleTest configuration
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1)
FetchContent_MakeAvailable(googletest)

# Include the GoogleTest headers
target_include_directories(UnderstandAlgo_lib PUBLIC ${googletest_SOURCE_DIR}/googletest/include)

option(BUILD_TESTS "Build Unit Tests" ON)
if(BUILD_TESTS)
    enable_testing()
    include(GoogleTest)
    # Include the header files for the testing executable if needed
    add_executable(tests test/test_main.cpp test/DerivedGraphTesting.cpp)
    target_link_libraries(tests PRIVATE UnderstandAlgo_lib gtest gtest_main)
    gtest_discover_tests(tests)
endif()