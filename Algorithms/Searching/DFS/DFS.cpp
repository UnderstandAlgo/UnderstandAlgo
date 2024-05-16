#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph {
    int V; // Number of vertices

    // An array of lists, list i is adjacency list of vertex i.
    vector<list<int>> adj;

public:
    Graph(int V); // ctor

    void addEdge(int v, int w); // Function to add edge to graph
    void DFS(int v); // Function to print a DFS traversal

private:
    void DFSVisit(int v, vector<bool>& visited); // Function to flag visited nodes in DFS
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V); // Resize the vector to hold 'V' number of lists
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // add w to v's list
}

void Graph::DFSVisit(int v, vector<bool>& visited) {
    // Mark current node visit and print it
    visited[v] = true;
    cout << v << " ";

    // Recur for all vertices v adjacent to this vertex v
    list<int>::iterator it;
    for (it = adj[v].begin(); it != adj[v].end(); ++it)
        if (!visited[*it])
            DFSVisit(*it, visited);
}

void Graph::DFS(int v) {
    // Mark all vertices not visited
    vector<bool> visited(V, false);

    // call recursive helper to print DFS traversal
    DFSVisit(v, visited);
}