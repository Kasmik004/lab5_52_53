#include <iostream>
#include <vector>
#include <utility>

class Graph
{

    bool is_directed;
    std::vector<std::pair<int, std::vector<int>>> *adjacency_list;

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
        if (isDirected())
        {
            for (auto i = adjacency_list->begin(); i != adjacency_list->end(); i++)
            {
                if (i->first == v1)
                {
                    i->second.push_back(v2);
                    return true;
                }
            }
            return false;
        }
        else
        {
            for (auto i = adjacency_list->begin(); i != adjacency_list->end(); i++)
            {
                if (i->first == v1)
                {
                    i->second.push_back(v2);
                }
                if (i->first == v2)
                {
                    i->second.push_back(v1);
                }
            }
            return true;
        }
    }

    bool removeVertex(int v)
    {
        for (auto i = adjacency_list->begin(); i != adjacency_list->end(); i++)
        {
            if (i->first == v)
            {
                adjacency_list->erase(i);
                return true;
            }
        }
        return false;
    }

    bool removeEdge(int v1, int v2)
    {
        if (isDirected())
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
        else
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
                        }
                    }
                }
                if (i->first == v2)
                {
                    for (auto j = i->second.begin(); j != i->second.end(); j++)
                    {
                        if (*j == v1)
                        {
                            i->second.erase(j);
                        }
                    }
                }
            }
            return true;
        }
    }

    int numVertices() const
    {
        return adjacency_list->size();
    }
};
