#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <vector>

template<typename VerticeType, typename EdgeType>
class Graph {
public:
    /**
    * @brief Add a vertex to the graph.
    *
    * This function is a pure virtual function (indicated by "= 0"), meaning
    * it is required to be implemented by any non-abstract class that inherits from this class
    *
    * @param vertex The vertex to be added.
    */
    virtual void addVertex(const VerticeType& vertex) = 0;

    /**
    * @brief Remove a vertex from the graph.
    *
    * This function is a pure virtual function, meaning
    * it is required to be implemented by any non-abstract class that inherits from this class.
    *
    * @param vertex The vertex to be removed.
    */
    virtual void removeVertex(const VerticeType& vertex) = 0;

    /**
    * @brief Adds an edge to the graph.
    *
    * This function is a pure virtual function, meaning
    * it is required to be implemented by any non-abstract class that inherits from this class. This function
    * must be overridden by any derived classes.
    *
    * @param source The source vertex where the edge should start.
    * @param destination The destination vertex where the edge should end.
    * @param weight The weight of the edge.
    */
    virtual void addEdge(const VerticeType &source, const VerticeType &destination, const EdgeType &weight) = 0;

    /**
    * @brief Adds an edge between two vertices. When the graph is directed,
    * the edge is added from vertex1 to vertex2. When it is not directed,
    * the edge is added from vertex2 to vertex1 as well.
    *
    * This function is a pure virtual function, meaning
    * it is required to be implemented by any non-abstract class that inherits from this class.
    *
    * @param source The source vertex.
    * @param destination The target vertex.
    * @param weight The weight of the edge.
    * @param isDirected (optional) Flag indicating if the graph is directed. If true, the edge is directed from source to destination.
    * Default is false, which means the edge is bidirectional.
    */
    virtual void addEdge(const VerticeType& source, const VerticeType& destination,
                         const EdgeType& weight, bool isDirected = false) = 0;

    /**
    * @brief Removes the edge between the provided vertices
    *
    * This function is a pure virtual function, meaning
    * it is required to be implemented by any non-abstract class that inherits from this class.
    *
    * @param vertex1 The first vertex.
    * @param vertex2 The second vertex.
    */
    virtual void removeEdge(const VerticeType& vertex1, const VerticeType& vertex2) = 0;

    /**
    * @brief Gets the total number of vertices in the graph.
    *
    * This function is a pure virtual function, meaning
    * it is required to be implemented by any non-abstract class that inherits from this class.
    *
    * @return unsigned int The total number of vertices.
    */
    virtual unsigned int numVertices() const = 0;

    /**
    * @brief Gets the total number of edges in the graph.
    *
    * This function is a pure virtual function, meaning
    * it is required to be implemented by any non-abstract class that inherits from this class.
    *
    * @return unsigned int The total number of edges.
    */
    virtual unsigned int numEdges() const = 0;
};

template<typename VerticeType, typename EdgeType>
class DerivedGraph: public Graph<VerticeType, EdgeType> {
private:
    std::unordered_map<VerticeType, std::vector<std::pair<VerticeType, EdgeType>>> adjacencyList; // Private member holding the adjacency list of the graph
public:
    DerivedGraph(); // Default Constructor of DerivedGraph class

    void addVertex(const VerticeType& vertex) override; // Overridden addVertex() function
    void removeVertex(const VerticeType &vertex) override; // Overridden removeVertex() function
    void addEdge(const VerticeType &source, const VerticeType &destination, const EdgeType &weight) override; // Overridden addEdge() function
    void addEdge(const VerticeType &source, const VerticeType &destination, const EdgeType &weight, bool isDirected) override; // Overridden addEdge() function with additional isDirected parameter
    void removeEdge(const VerticeType &vertex1, const VerticeType &vertex2) override; // Overridden removeEdge() function
    unsigned int numVertices() const override; // Overridden numVertices() function
    unsigned int numEdges() const override; // Overridden numEdges() function

};
#include "Graph.tpp"
#endif // GRAPH_H