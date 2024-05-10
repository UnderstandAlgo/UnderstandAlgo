#include <gtest/gtest.h>
#include "../Structures/Static/StaticArray.h"

// You want to go into the cmake-build-debug directory and run ./Google_Test_run
// Make sure you rebuild/recompile after changing.

TEST(StaticArrayTest, SizeOfArrayShouldBeDeclaredInTemplate) {
    StaticArray<int, 10> array{};
    EXPECT_EQ(array.size(), 10);
}

TEST(StaticArrayTest, CanAddElementsToArray) {
    StaticArray<int, 10> array{};
    array[0] = 10;
    EXPECT_EQ(array[0], 10);
    EXPECT_EQ(array.size(), 10);
}

TEST(StaticArrayTest, AddedElementsPersist) {
    StaticArray<int, 10> array{};
    array[0] = 10;
    array[1] = 20;
    EXPECT_EQ(array[0], 10);
    EXPECT_EQ(array[1], 20);
    EXPECT_EQ(array.size(), 10);
}
