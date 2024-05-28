// Created by Aaron H on 5/28/24.
// Created by Aaron H on 5/28/24.
#include <gtest/gtest.h>
#include "../Structures/ADT/Graph.hpp"

// Define a type of graph to test, we will work with a graph of primitive int with integer weights.
typedef DerivedGraph<int, int> IntGraph;

// Edge Case: Adding and Removing Vertices in the Graph
TEST(GraphTest, AddAndRemoveVertices){
    IntGraph g; // Instantiation

    // Add vertices
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    EXPECT_EQ(g.numVertices(), 3); // Check if vertices count increases

    // Remove vertices
    g.removeVertex(1);
    g.removeVertex(2);
    g.removeVertex(3);
    EXPECT_EQ(g.numVertices(), 0); // Check if vertices count decreases
}