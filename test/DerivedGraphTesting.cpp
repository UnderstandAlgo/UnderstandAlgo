// Created by Aaron H on 5/28/24.
#include "../Structures/ADT/Graph.hpp"
#include <gtest/gtest.h>

TEST(DerivedGraphTest, TestNumVertices) {
    DerivedGraph<int, int> graph;
    ASSERT_EQ(graph.numVertices(), 0);
    graph.addVertex(1);
    ASSERT_EQ(graph.numVertices(), 1);
}

TEST(DerivedGraphTest, TestNumEdges) {
    DerivedGraph<int, int> graph;
    ASSERT_EQ(graph.numEdges(), 0);
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addEdge(1, 2, 3);
    ASSERT_EQ(graph.numEdges(), 1);
}

TEST(DerivedGraphTest, TestAddVertex) {
    DerivedGraph<int, int> graph;
    graph.addVertex(1);
    ASSERT_EQ(graph.numVertices(), 1);
}

TEST(DerivedGraphTest, AddExistingVertex) {
    DerivedGraph<int, int> graph;
    graph.addVertex(1);
    // Modify this to match your error handling implementation.
    ASSERT_THROW(graph.addVertex(1), std::runtime_error);
}

TEST(DerivedGraphTest, TestAddEdge) {
    DerivedGraph<int, int> graph;
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addEdge(1, 2, 3);
    ASSERT_EQ(graph.numEdges(), 1);
}

TEST(DerivedGraphTest, AddEdgeWithNonexistentVertex) {
    DerivedGraph<int, int> graph;
    // Modify this according to your error handling implementation.
    ASSERT_THROW(graph.addEdge(1, 2, 3), std::runtime_error);

    graph.addVertex(1);
    ASSERT_THROW(graph.addEdge(1, 2, 3), std::runtime_error);
    ASSERT_THROW(graph.addEdge(2, 1, 3), std::runtime_error);
}

TEST(DerivedGraphTest, TestRemoveEdge) {
    DerivedGraph<int, int> graph;
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addEdge(1, 2, 3);
    graph.removeEdge(1, 2);
    ASSERT_EQ(graph.numEdges(), 0);
}

TEST(DerivedGraphTest, RemoveNonexistentEdge) {
    DerivedGraph<int, int> graph;
    // Modify this according to your error handling implementation.
    ASSERT_THROW(graph.removeEdge(1, 2), std::runtime_error);

    graph.addVertex(1);
    graph.addVertex(2);
    ASSERT_THROW(graph.removeEdge(1, 2), std::runtime_error);
}

TEST(DerivedGraphTest, TestRemoveVertex) {
    DerivedGraph<int, int> graph;
    graph.addVertex(1);
    graph.removeVertex(1);
    ASSERT_EQ(graph.numVertices(), 0);
}

TEST(DerivedGraphTest, RemoveNonexistentVertex) {
    DerivedGraph<int, int> graph;
    // Modify this according to your error handling implementation.
    ASSERT_THROW(graph.removeVertex(1), std::runtime_error);

    graph.addVertex(1);
    graph.removeVertex(1);
    ASSERT_THROW(graph.removeVertex(1), std::runtime_error);
}