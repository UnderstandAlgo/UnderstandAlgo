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

TEST(StaticArrayTest, OutOfBoundException) {
    StaticArray<int, 10> array{};
    EXPECT_THROW(array.at(10), std::out_of_range);
}

TEST(StaticArrayTest, CheckFrontAndBack) {
    StaticArray<int, 10> array{};
    array[0] = 10;
    array[9] = 20;
    EXPECT_EQ(array.front(), 10);
    EXPECT_EQ(array.back(), 20);
}

TEST(StaticArrayTest, CheckEmpty) {
    StaticArray<int, 0> array{};
    EXPECT_TRUE(array.empty());
}

TEST(StaticArrayTest, CheckFill) {
    StaticArray<int, 10> array{};
    array.fill(5);
    for (int i : array) {
        EXPECT_EQ(i, 5);
    }
}

TEST(StaticArrayTest, CheckSwap) {
    StaticArray<int, 3> array1{};
    array1[0] = 1;
    array1[1] = 2;
    array1[2] = 3;

    StaticArray<int, 3> array2{};
    array2[0] = 4;
    array2[1] = 5;
    array2[2] = 6;

    EXPECT_EQ(array1[0], 1);
    EXPECT_EQ(array1[1], 2);
    EXPECT_EQ(array1[2], 3);
    EXPECT_EQ(array2[0], 4);
    EXPECT_EQ(array2[1], 5);
    EXPECT_EQ(array2[2], 6);

    array1.swap(array2);

    EXPECT_EQ(array1[0], 4);
    EXPECT_EQ(array1[1], 5);
    EXPECT_EQ(array1[2], 6);
    EXPECT_EQ(array2[0], 1);
    EXPECT_EQ(array2[1], 2);
    EXPECT_EQ(array2[2], 3);

}
