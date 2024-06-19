#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

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
};

#endif
