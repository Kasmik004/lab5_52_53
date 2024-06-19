#include <iostream>
#include <vector>
#include <utility>

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
        return false;
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

    int numEdges()
    {
        int count = 0;
        for (int i = 0; i < adjacency_list->size(); i++)
        {
            count += adjacency_list->at(i).second.size();
        }
        return count;
    };
    int indegree(int v)
    {
        int count = 0;
        for (int i = 0; i < adjacency_list->size(); i++)
        {
            for (int j = 0; j < adjacency_list->at(i).second.size(); j++)
            {
                if (adjacency_list->at(i).second[j] == v)
                {
                    count++;
                }
            }
        }
        return count;
    };
    int outdegree(int v)
    {
        int count = 0 for (int i = 0; i < adjacency_list->size(); i++)
        {
            if (adjacency_list->at(i).first() == v)
            {
                count += adjacency_list->at(i).second.size();
            }
        }

        return adjacency_list->at(v).second.size();
    };
    int degree(int v)
    {
        return adjacency_list->at(v).second.size() + indegree(v);
    };
    void neighbors(int v)
    {
        for (int i = 0; i < adjacency_list->at(v).second.size(); i++)
        {
            std::cout << adjacency_list->at(v).second[i] << " ";
        }
        std::cout << std::endl;
    };
    void checkNeighbors(int v, int w)
    {
        for (int i = 0; i < adjacency_list->at(v).second.size(); i++)
        {
            if (adjacency_list->at(v).second[i] == w)
            {
                std::cout << "True" << std::endl;
                return;
            }
        }
        std::cout << "False" << std::endl;
    };
};
