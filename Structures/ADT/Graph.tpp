#include "Graph.hpp"

//Begin implementation of ElementaryGraph template methods

template<typename VerticeType, typename EdgeType>
DerivedGraph<VerticeType, EdgeType>::DerivedGraph() {
    adjacencyList = std::unordered_map<VerticeType, std::vector<std::pair<VerticeType, EdgeType>>>();
}

template<typename VerticeType, typename EdgeType>
void DerivedGraph<VerticeType, EdgeType>::addVertex(const VerticeType& vertex) {
    adjacencyList.insert({vertex, std::vector<std::pair<VerticeType, EdgeType>>()});
}

template<typename VerticeType, typename EdgeType>
void DerivedGraph<VerticeType, EdgeType>::removeVertex(const VerticeType &vertex) {
    adjacencyList.erase(vertex);

    for (auto &vertexPair : adjacencyList) {
        vertexPair.second.erase(std::remove_if(vertexPair.second.begin(), vertexPair.second.end(),[&vertex]
        (const std::pair<VerticeType, EdgeType>& edgePair) { return edgePair.first == vertex; } ), vertexPair.second.end());
    }
}

template<typename VerticeType, typename EdgeType>
void DerivedGraph<VerticeType, EdgeType>::addEdge(const VerticeType &source, const VerticeType &destination, const EdgeType &weight) {
    this->addEdge(source, destination, weight, false);  // calling second function with isDirected as false.
}

template<typename VerticeType, typename EdgeType>
void DerivedGraph<VerticeType, EdgeType>::addEdge(const VerticeType &source, const VerticeType &destination, const EdgeType &weight, bool isDirected) {
    adjacencyList[source].push_back({destination, weight});
    if (!isDirected) {
        adjacencyList[destination].push_back({source, weight});
    }
}

template<typename VerticeType, typename EdgeType>
void DerivedGraph<VerticeType, EdgeType>::removeEdge(const VerticeType &vertex1, const VerticeType &vertex2) {
    std::vector<std::pair<VerticeType, EdgeType>>& edges1 = adjacencyList[vertex1];
    std::vector<std::pair<VerticeType, EdgeType>>& edges2 = adjacencyList[vertex2];

    edges1.erase(std::remove_if(edges1.begin(), edges1.end(),
                                [&vertex2](const std::pair<VerticeType,EdgeType>& edgePair) { return edgePair.first == vertex2; } ), edges1.end());

    edges2.erase(std::remove_if(edges2.begin(), edges2.end(),
                                [&vertex1](const std::pair<VerticeType,EdgeType>& edgePair) { return edgePair.first == vertex1; } ), edges2.end());
}

template<typename VerticeType, typename EdgeType>
unsigned int DerivedGraph<VerticeType, EdgeType>::numVertices() const {
    return adjacencyList.size();
}

template<typename VerticeType, typename EdgeType>
unsigned int DerivedGraph<VerticeType, EdgeType>::numEdges() const {
    unsigned int count = 0;
    for (const auto &vertexPair : adjacencyList) {
        count += vertexPair.second.size();
    }
    return count / 2;
}