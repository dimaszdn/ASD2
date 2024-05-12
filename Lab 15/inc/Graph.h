#pragma once

#include <vector>
#include<algorithm>

class Graph
{
private:
    std::vector<std::vector<int>> adjList{};
    std::vector<int> degrees{};
    std::vector<int> colors{};
    int V{};

public:
    explicit Graph(int n) : V(n),
                            adjList(n),
                            degrees(n),
                            colors(n)
    {}

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
    }

    void countDegrees()
    {
        for (int i = 0; i < V; ++i)
            degrees[i] = adjList[i].size();
    }

    std::vector<int> colorize()
    {
        this->countDegrees();

        std::vector<int> nodes(V);
        for (int i = 0; i < V; ++i)
            nodes[i] = i;

        std::sort(nodes.begin(), nodes.end(), [&](int a, int b)
        {
            return degrees[a] > degrees[b];
        });

        for (auto node : nodes)
            std::cout << node << " ";
        std::cout << "\n";

        int curColor = 1;
        std::vector<bool> colored(V, false);
        for (auto u : nodes)
        {
            if (!colored[u])
            {
                colors[u] = curColor;
                colored[u] = true;
                for (auto v : nodes)
                {
//                    if (!colored[v] && std::find(adjList[u].begin(), adjList[u].end(), v) == adjList[u].end())
                    if (!colored[v] && !matchedColor(v, curColor))
                    {
                        colors[v] = curColor;
                        colored[v] = true;
                    }
                }
                ++curColor;
            }
        }
        return colors;
    }

    bool matchedColor(int u, int color)
    {
        for (auto v : adjList[u])
        {
            if (colors[v] == color)
                return true;
        }
        return false;
    }
};