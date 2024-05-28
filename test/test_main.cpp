// Created by Aaron H on 5/26/24.
// NOTE: currently we are using main as our main entry point into the testing suite.
// For now the project's (non-testing logic should not be here) when dealing with a project structure like this
// For actual program logic, we will go into the UnderstandAlgo_lib library and have a different main.cpp or equivalent.

// When
#include "gtest/gtest.h"
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}