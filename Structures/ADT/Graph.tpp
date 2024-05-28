#include "Graph.hpp"
#include <algorithm>

template<typename V, typename E>
void DerivedGraph<V, E>::addVertex(const V& vertex) {
    // Insert vertex with empty list
    map[vertex] = std::vector<std::pair<V, E>>();
}

template<typename V, typename E>
void DerivedGraph<V, E>::removeVertex(const V& vertex) {
    // Remove vertex from the map
    map.erase(vertex);
}

// NOTE: addEdge and removeEdge assume an undirected graph (edges run both ways)
// If we want to work with a directed graph (edges run one way) we will need to modify these methods
template<typename V, typename E>
void DerivedGraph<V, E>::addEdge(const V& vertex1, const V& vertex2, const E& edge) {
    // Ensure both vertices exist in graph
    if (map.find(vertex1) != map.end() && map.find(vertex2) != map.end()) {
        // Add the edge from V1 to V2
        map[vertex1].push_back(std::make_pair(vertex2, edge));
        // Add the edge from V2 to V1
        map[vertex2].push_back(std::make_pair(vertex1, edge));
    }
}

template<typename V, typename E>
void DerivedGraph<V, E>::removeEdge(const V& vertex1, const V& vertex2) {
    if (map.find(vertex1) != map.end() && map.find(vertex2) != map.end()) {
        // Remove the edge from V1 to V2
        auto &edges1 = map[vertex1];
        // I'm mixing a lambda inside algorithm
        edges1.erase(std::remove_if(edges1.begin(), edges1.end(), [&](const std::pair<V, E>& edge) {
            return edge.first == vertex2;
        }), edges1.end());
        // Remove the edge from V2 to V1
        auto &edges2 = map[vertex2];
        edges2.erase(std::remove_if(edges2.begin(), edges2.end(), [&](const std::pair<V, E> &edge) {
            return edge.first == vertex1;
        }), edges2.end());
    }
}

template<typename V, typename E>
unsigned int DerivedGraph<V, E>::numVertices() const {
    // The number of vertices is the number of keys in the map.
    return map.size();
}

template<typename V, typename E>
unsigned int DerivedGraph<V, E>::numEdges() const {
    int count = 0;
    // For each vertex, count all of its edges
    for (const auto &pair: map) {
        count += pair.second.size();
    }
    // Since we double count each edge, divide by 2
    return count / 2;
}