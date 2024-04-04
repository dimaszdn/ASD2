#pragma once

#include<vector>
#include<sstream>
#include<fstream>
#include<string>
#include<iostream>

class Graph
{
private:
    std::vector<std::vector<bool>> graph;
    std::vector<std::vector<bool>> graphR;
    std::vector<int> visited;
    std::vector<int> order;
    int countScc = 0;

public:
    explicit Graph(const std::string& path)
    {
        this->getMatrixFromFile(path);
        graphR.resize(graph.size());
        graphToGraphR(); //step 1
    }

    void topologicalSort(int node)
    {
        visited[node] = 1;
        for (int next = 0; next < graphR[node].size(); ++next)
            if (!visited[next] && graphR[node][next])
                topologicalSort(next);
        order.push_back(node);
    }

    void dfs(int node, int count)
    {
        visited[node] = count;
        for (int next = 0; next < graph.size(); ++next)
            if (!visited[next] && graph[node][next])
                dfs(next, count);
    }

    void findScc()
    {
        visited.assign(graph.size(), 0);
        for (int node = 0; node < graph.size(); ++node) //step 2
            if (!visited[node])
                topologicalSort(node);
        std::reverse(order.begin(), order.end());

        visited.assign(graph.size(), 0);
        for (int node : order) //step 3
            if (!visited[node])
                dfs(node, ++countScc);
    }

    void showSccAndCount()
    {
        std::cout << "Count scc: " << countScc << "\n";
        std::cout << "Their structure: " << "\n";
        for (int i = 0; i < countScc; ++i)
        {
            for (int j = 0; j < visited.size(); ++j)
            {
                if (visited[j] == i + 1)
                    std::cout << j << " ";
            }
            std::cout << "\n";
        }
    }

private:
    void getMatrixFromFile(const std::string& path)
    {
        std::ifstream file(path);
        if (!file.is_open())
            throw std::exception("File opening error");
        else
        {
            std::string row;
            while (std::getline(file, row))
                graph.push_back(convertToRowMatrix(row));
        }
    }

    std::vector<bool> convertToRowMatrix(const std::string& row)
    {
        std::vector<bool> rowMatrix;
        std::istringstream is(row);
        bool value;
        while(is >> value)
            rowMatrix.push_back(value);
        return rowMatrix;
    }

    void graphToGraphR()
    {
        for (int i = 0; i < graph.size(); ++i)
            for (int j = 0; j < graph.size(); ++j)
                graphR[i].push_back(graph[j][i]);
    }
};