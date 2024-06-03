#include "Graph.hpp"

//Begin implementation of ElementaryGraph template methods

template<typename VerticeType, typename EdgeType>
DerivedGraph<VerticeType, EdgeType>::DerivedGraph() {
    adjacencyList = std::unordered_map<VerticeType, std::vector<std::pair<VerticeType, EdgeType>>>();
}

template<typename VerticeType, typename EdgeType>
void DerivedGraph<VerticeType, EdgeType>::addVertex(const VerticeType& vertex) {
    // Check if the vertex already exists
    if (adjacencyList.find(vertex) != adjacencyList.end()) {
        // Vertex found, so throw an exception
        throw std::runtime_error("Vertex already exists in the graph");
    }

    // If the vertex does not already exist, add it into the adjacency list
    adjacencyList.insert({vertex, std::vector<std::pair<VerticeType, EdgeType>>()});
}

template<typename VerticeType, typename EdgeType>
void DerivedGraph<VerticeType, EdgeType>::removeVertex(const VerticeType &vertex) {
    auto it = adjacencyList.find(vertex);

    if (it == adjacencyList.end()) {
        throw std::runtime_error("Vertex does not exist in the graph");
    }

    adjacencyList.erase(it);

    for (auto &vertexPair : adjacencyList) {
        vertexPair.second.erase(std::remove_if(vertexPair.second.begin(), vertexPair.second.end(),
                                               [&vertex](const std::pair<VerticeType, EdgeType>& edgePair) { return edgePair.first == vertex; } ),
                                vertexPair.second.end());
    }
}

template<typename VerticeType, typename EdgeType>
void DerivedGraph<VerticeType, EdgeType>::addEdge(const VerticeType &source, const VerticeType &destination, const EdgeType &weight) {
    // First, let's ensure both vertices exist
    if (adjacencyList.find(source) == adjacencyList.end() || adjacencyList.find(destination) == adjacencyList.end()) {
        throw std::runtime_error("One or both vertices do not exist in the graph");
    }
    // If vertices exist, call the directed edge function with isDirected set to false.
    this->addEdge(source, destination, weight, false);
}

template<typename VerticeType, typename EdgeType>
void DerivedGraph<VerticeType, EdgeType>::addEdge(const VerticeType &source, const VerticeType &destination, const EdgeType &weight, bool isDirected) {
    // Ensure both vertices exist in the graph
    if (adjacencyList.find(source) == adjacencyList.end() || adjacencyList.find(destination) == adjacencyList.end()) {
        throw std::runtime_error("One or both vertices do not exist in the graph");
    }
    // If vertices exist, create edges
    adjacencyList[source].push_back({destination, weight});
    if (!isDirected) {
        adjacencyList[destination].push_back({source, weight});
    }
}

template<typename VerticeType, typename EdgeType>
void DerivedGraph<VerticeType, EdgeType>::removeEdge(const VerticeType& vertex1, const VerticeType& vertex2) {
    auto it1 = adjacencyList.find(vertex1);
    auto it2 = adjacencyList.find(vertex2);

    if (it1 == adjacencyList.end() || it2 == adjacencyList.end()) {
        throw std::runtime_error("One or both vertices do not exist in the graph");
    }

    // Try removing edge from vertex1's edge list
    auto& edges1 = it1->second;
    auto edge1 = std::remove_if(edges1.begin(), edges1.end(),
                                [&vertex2](const std::pair<VerticeType, EdgeType>& edgePair){ return edgePair.first == vertex2; });
    if (edge1 == edges1.end()) {
        throw std::runtime_error("Edge does not exist in the graph");
    }
    edges1.erase(edge1, edges1.end());

    // Try removing edge from vertex2's edge list
    auto& edges2 = it2->second;
    auto edge2 = std::remove_if(edges2.begin(), edges2.end(),
                                [&vertex1](const std::pair<VerticeType, EdgeType>& edgePair){ return edgePair.first == vertex1; });
    if (edge2 == edges2.end()) {
        throw std::runtime_error("Edge does not exist in the graph");
    }
    edges2.erase(edge2, edges2.end());
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