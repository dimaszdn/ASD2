#pragma once

#include<string>
#include <algorithm>

#include<DisjointSetUnion.h>
#include<Edge.h>

class Graph
{
private:
    std::vector<Edge> edges;
    Union* un{};

public:
    Graph() = default;

    explicit Graph(size_t count)
    {
        un = new Union(count);
    }

    ~Graph()
    {
        if (un != nullptr)
            delete un;
    }

    void addEdge(Edge edge)
    {
        edges.push_back(edge);
    }

    std::vector<Edge> kruskal()
    {
        std::vector<Edge> result;
        std::sort(edges.begin(), edges.end());

        for (auto edge : edges)
        {
            if (un->leader(edge.begin) != un->leader(edge.end))
            {
                result.push_back(edge);
                un->unite(edge.begin, edge.end);
            }
        }
        return result;
    }
};

void fillGraph(const std::vector<std::vector<int>>& adjMatrix, Graph& graph)
{
    for (int i = 0; i < adjMatrix.size(); ++i)
        for (int j = 0; j < adjMatrix.size(); ++j)
        {
            if (adjMatrix[i][j] > 0)
                graph.addEdge(Edge(i, j, adjMatrix[i][j]));
        }
}