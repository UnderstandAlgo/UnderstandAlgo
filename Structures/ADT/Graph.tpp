#include "Graph.hpp"
template<typename V, typename E>
void DerivedGraph<V, E>::addVertex(const V& vertex) {
    map.insert({vertex, std::vector<std::pair<V, E>>()});
}

template<typename V, typename E>
void DerivedGraph<V, E>::removeVertex(const V &vertex) {
    // Remove the vertex along with edges
    map.erase(vertex);

    // If graph is undirected, edges coming to this vertex also need to be removed
    for (auto &i : map) {
        i.second.erase(std::remove_if(i.second.begin(), i.second.end(),
                                      [&vertex](const std::pair<V,E>& elt) { return elt.first == vertex; } ), i.second.end());
    }
}

template<typename V, typename E>
void DerivedGraph<V, E>::addEdge(const V &vertex1, const V &vertex2, const E &edge) {
    map[vertex1].push_back({vertex2, edge});

    // For undirected, also add reverse edge
    map[vertex2].push_back({vertex1, edge});
}

template<typename V, typename E>
void DerivedGraph<V, E>::removeEdge(const V &vertex1, const V &vertex2) {
    // Assuming undirected, so remove from both vertices
    std::vector<std::pair<V, E>>& edges1 = map[vertex1];
    std::vector<std::pair<V, E>>& edges2 = map[vertex2];

    edges1.erase(std::remove_if(edges1.begin(), edges1.end(),
                                [&vertex2](const std::pair<V,E>& elt) { return elt.first == vertex2; } ), edges1.end());

    edges2.erase(std::remove_if(edges2.begin(), edges2.end(),
                                [&vertex1](const std::pair<V,E>& elt) { return elt.first == vertex1; } ), edges2.end());
}

template<typename V, typename E>
unsigned int DerivedGraph<V, E>::numVertices() const {
    return map.size();
}

template<typename V, typename E>
unsigned int DerivedGraph<V, E>::numEdges() const {
    unsigned int count = 0;
    for (const auto &i : map) {
        count += i.second.size();
    }
    return count / 2; // Since undirected, edges count is twice
}