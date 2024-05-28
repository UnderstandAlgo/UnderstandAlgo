#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <vector>

template<typename V, typename E>
class Graph {
public:
    virtual void addVertex(const V& vertex) = 0;
    virtual void removeVertex(const V& vertex) = 0;
    virtual void addEdge(const V& vertex1, const V& vertex2, const E& edge) = 0;
    virtual void removeEdge(const V& vertex1, const V& vertex2) = 0;
    virtual unsigned int numVertices() const = 0;
    virtual unsigned int numEdges() const = 0;
};

template<typename V, typename E>
class DerivedGraph: public Graph<V, E> {
private:
    std::unordered_map<V, std::vector<std::pair<V, E>>> map;
public:
    DerivedGraph() {
        map = std::unordered_map<V, std::vector<std::pair<V, E>>>();
    }

    void addVertex(const V& vertex) override;
    void removeVertex(const V &vertex) override;
    void addEdge(const V &vertex1, const V &vertex2, const E &edge) override;
    void removeEdge(const V &vertex1, const V &vertex2) override;
    unsigned int numVertices() const override;
    unsigned int numEdges() const override;
};

#include "Graph.tpp" // Include the implementation here.
#endif
