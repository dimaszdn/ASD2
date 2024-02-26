#pragma once

#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<queue>
#include<stack>

//вспомогательная функция для getMatrixFromFile
std::vector<bool> convertToRowMatrix(const std::string& row)
{
    std::vector<bool> rowMatrix;
    std::istringstream is(row);
    bool value;
    while(is >> value)
        rowMatrix.push_back(value);
    return rowMatrix;
}

std::vector<std::vector<bool>> getMatrixFromFile(const std::string& path)
{
    std::vector<std::vector<bool>> matrix;
    std::ifstream file(path);

    if (!file.is_open())
        throw std::exception("File opening error");
    else
    {
        std::string row;
        while (std::getline(file, row))
            matrix.push_back(convertToRowMatrix(row));
    }

    return matrix;
}

struct Edge
{
    int begin, end;

    Edge(int begin, int end)
    {
        this->begin = begin;
        this->end = end;
    }
};
std::ostream& operator << (std::ostream &os, const Edge &edge)
{
    return os << edge.begin << " " << edge.end;
}

void shortWay(const std::vector<Edge>& edges, int finish)
{
    std::cout << finish;
    for (int i = edges.size() - 1; i >= 0; --i)
    {
        if (edges[i].end == finish)
        {
            finish = edges[i].begin;
            std::cout << " <-- " << finish;
        }
    }
}

std::vector<Edge> BFS(const std::vector<std::vector<bool>>& adjMatrix, int start, int finish)
{
    std::queue<int> searchQueue;
    std::vector<bool> searched(adjMatrix[0].size()); //сюда складываем найденных, чтобы избежать циклов
    std::vector<Edge> edges; //вектор рёбер для восстановления пути

    searchQueue.push(start - 1);
    while (!searchQueue.empty())
    {
        int node = searchQueue.front();
        searchQueue.pop();
        if (!searched[node])
        {
            searched[node] = 1;
            for (int col = 0; col < adjMatrix[node].size(); ++col)
            {
                if (adjMatrix[node][col] == 1)
                {
                    searchQueue.push(col);
                    //поиск кратчайшего пути
                    edges.push_back(Edge(node + 1, col + 1));
                    if (col == finish - 1)
                        return edges;
                }
            }
        }
    }
}