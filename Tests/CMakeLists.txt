# Add a testing executable
add_executable(runUnitTests StaticArrayTest.cpp)
target_link_libraries(runUnitTests gtest gtest_main)