#include <iostream>
#include <vector>
#include <utility>
#include <ctime>
#include <cstdlib>

class Graph
{
    bool is_directed;
    std::vector<std::pair<int, std::vector<int>>> *adjacency_list;

    bool removeEdgeDirected(int v1, int v2)
    {
        for (auto i = adjacency_list->begin(); i != adjacency_list->end(); i++)
        {
            if (i->first == v1)
            {
                for (auto j = i->second.begin(); j != i->second.end(); j++)
                {
                    if (*j == v2)
                    {
                        i->second.erase(j);
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool checkNeighbourSingle(int v, int w) const
    {
        std::vector<int> neighbours = this->neighbours(v);
        for (auto j = neighbours.begin(); j != neighbours.end(); j++)
        {
            if (*j == w)
            {
                return true;
            }
        }
        return false;
    }

public:
    Graph(bool is_directed) : is_directed(is_directed)
    {
        adjacency_list = new std::vector<std::pair<int, std::vector<int>>>();
    }

    bool isEmpty() const
    {
        return adjacency_list->empty();
    }

    bool isDirected() const
    {
        return is_directed;
    }

    bool addVertex(int v)
    {
        for (auto i = adjacency_list->begin(); i != adjacency_list->end(); i++)
        {
            if (i->first == v)
            {
                return false;
            }
        }
        std::vector<int> v_adj;
        adjacency_list->push_back(std::make_pair(v, v_adj));
        return true;
    }

    bool addEdge(int v1, int v2)
    {
        bool v1_found = false, v2_found = false;
        for (auto i = adjacency_list->begin(); i != adjacency_list->end(); i++)
        {
            if (i->first == v1)
            {
                i->second.push_back(v2);
                v1_found = true;
            }
            if (!isDirected() && i->first == v2)
            {
                i->second.push_back(v1);
                v2_found = true;
            }
        }
        return v1_found && (isDirected() || v2_found);
    }

    bool removeVertex(int v)
    {
        for (auto i = adjacency_list->begin(); i != adjacency_list->end(); i++)
        {
            if (i->first == v)
            {
                adjacency_list->erase(i);
                break;
            }
            else
            {
                for (auto j = i->second.begin(); j != i->second.end(); j++)
                {
                    if (*j == v)
                    {
                        i->second.erase(j);
                        break;
                    }
                }
            }
        }

        for (auto i = adjacency_list->begin(); i != adjacency_list->end(); i++)
        {
            for (auto j = i->second.begin(); j != i->second.end(); j++)
            {
                if (*j == v)
                {
                    i->second.erase(j);
                    break;
                }
            }
        }
        return true;
    }

    bool removeEdge(int v1, int v2)
    {
        if (isDirected())
        {
            return removeEdgeDirected(v1, v2);
        }
        else
        {
            return removeEdgeDirected(v1, v2) && removeEdgeDirected(v2, v1);
        }
    }

    int numVertices() const
    {
        return adjacency_list->size();
    }

    // Author (from numEdges): Kasmik Regmi

    int numEdges() const
    {
        int count = 0;
        for (auto i = adjacency_list->begin(); i != adjacency_list->end(); i++)
        {
            count += i->second.size();
        }
        return count;
    }

    int indegree(int v) const
    {
        int count = 0;
        for (auto j = adjacency_list->begin(); j != adjacency_list->end(); j++)
        {
            if (j->first != v)
            {
                for (auto i = j->second.begin(); i != j->second.end(); i++)
                {
                    if (*i == v)
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }

    int outdegree(int v) const
    {
        for (auto j = adjacency_list->begin(); j != adjacency_list->end(); j++)
        {
            if (j->first == v)
            {
                return j->second.size();
            }
        }
        return 0;
    }

    int degree(int v) const
    {
        return indegree(v) + outdegree(v);
    }

    std::vector<int> neighbours(int v) const
    {
        for (int i = 0; i < adjacency_list->size(); i++)
        {
            if (adjacency_list->at(i).first == v)
            {
                return adjacency_list->at(i).second;
            }
        }
        return std::vector<int>();
    }

    bool neighbour(int v, int w) const
    {
        if (isDirected())
        {
            return checkNeighbourSingle(v, w);
        }
        else
        {
            return checkNeighbourSingle(v, w) || checkNeighbourSingle(w, v);
        }
    }
};

void generateRandomGraph(Graph &graph, int numVertices, int numEdges)
{
    for (int i = 0; i < numVertices; i++)
    {
        graph.addVertex(i);
    }

    int v1, v2;
    for (int i = 0; i < numEdges; i++)
    {
        do
        {
            v1 = rand() % numVertices;
            v2 = rand() % numVertices;
        } while (v1 == v2 || graph.neighbour(v1, v2));

        graph.addEdge(v1, v2);
    }
}