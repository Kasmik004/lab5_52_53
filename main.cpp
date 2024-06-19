#include <iostream>
#include "src/graph.h"

int main()
{
    Graph g(true);

    if (g.isEmpty())
    {
        std::cout << "Graph is empty" << std::endl;
    }

    if (g.isDirected())
    {
        std::cout << "Graph is directed" << std::endl;
    }

    g.addVertex(1);
    g.addVertex(2);
    g.addEdge(1, 2);

    if (g.neighbour(1, 2))
    {
        std::cout << "1 is neighbour of 2" << std::endl;
    }

    if (g.neighbour(2, 1))
    {
        std::cout << "2 is neighbour of 1" << std::endl;
    }

    if (g.removeEdge(1, 2))
    {
        std::cout << "Edge 1-2 removed" << std::endl;
    }

    if (!g.neighbour(1, 2))
    {
        std::cout << "1 is not neighbour of 2" << std::endl;
    }

    if (!g.neighbour(2, 1))
    {
        std::cout << "2 is not neighbour of 1" << std::endl;
    }

    g.removeVertex(1);
    g.removeVertex(2);

    if (g.isEmpty())
    {
        std::cout << "Graph is empty" << std::endl;
    }

    return 0;
}