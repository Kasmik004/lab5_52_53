#include <iostream>
#include <vector>
#include <utility>

class Graph
{

private:
    bool is_directed;
    std::vector<std::pair<int, std::vector<int>>> *adjacency_list;

public:
    Graph(bool is_directed)
    {
        this->is_directed = is_directed;
        adjacency_list = new std::vector<std::pair<int, std::vector<int>>>(); // adjacency_list = new std::vector<std::pair<int, std::vector<int>>>();
    }

    int numVertices()
    {
        return adjacency_list->size();
    };
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
