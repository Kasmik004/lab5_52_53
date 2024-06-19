#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "graph.cpp"

class Graph
{

public:
    Graph(bool);
    bool isEmpty() const;
    bool isDirected() const;
    bool addVertex(int);
    bool addEdge(int, int);
    bool removeVertex(int);
    bool removeEdge(int, int);
    int numVertices() const;
    int numEdges() const;
    int indegree(int) const;
    int outdegree(int) const;
    int degree(int) const;
    std::vector<int> neighbours(int) const;
    bool neighbour(int v, int w) const;
};

#endif
