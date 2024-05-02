#pragma once

#include<vector>
#include<stack>

class Graph
{
private:
    std::vector<std::vector<bool>> adjMatrix{};
    std::vector<int> cycle{};

public:
    explicit Graph(std::vector<std::vector<bool>> matrix) : adjMatrix(std::move(matrix))
    {}

    bool isEuler()
    {
        if (countComponents() > 1)
            return false;

        int degree;
        for (int i = 0; i < adjMatrix.size(); ++i)
        {
            degree = 0;
            for (int j = 0; j < adjMatrix.size(); ++j)
            {
                if (adjMatrix[i][j])
                    degree++;
            }
            if (degree % 2 != 0)
                return false;
        }
        return true;
    }

    std::vector<int> findEulerCycle()
    {
        if (!isEuler())
            return {};

        std::vector<std::vector<bool>> copyAdjMatrix(adjMatrix);
        dfsForFindCycle(0, copyAdjMatrix);

        std::reverse(cycle.begin(), cycle.end());
        return cycle;
    }

private:
    int countComponents()
    {
        std::vector<bool> visited(adjMatrix.size(), false);
        int count = 0;
        for (int node = 0; node < visited.size(); ++node)
        {
            if (!visited[node])
            {
                ++count;
                if (count > 1)
                    return count;
                dfsForCount(node, visited);
            }
        }
        return count;
    }

    void dfsForCount(int node, std::vector<bool>& visited)
    {
        visited[node] = true;
        for (int to = 0; to < adjMatrix.size(); ++to)
        {
            if (adjMatrix[node][to] && !visited[to])
                dfsForCount(to, visited);
        }
    }

    void dfsForFindCycle(int node, std::vector<std::vector<bool>>& matrix)
    {
        //если удаляется мост, то происходит возврат в предыдущую вершину,
        //а текущая сохраняется в массив
        for (int to = 0; to < adjMatrix.size(); ++to)
        {
            if (matrix[node][to])
            {
                matrix[node][to] = false;
                matrix[to][node] = false;
                dfsForFindCycle(to, matrix);
            }
        }
        cycle.push_back(node);
    }
};