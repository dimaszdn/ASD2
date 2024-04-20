#pragma once

#include<vector>

/*
    Принцип схож с алгоритмом Дейкстры,
    только релаксация осуществляется
    по весу рёбер
*/

void prim(const std::vector<std::vector<int>>& adjMatrix)
{
    const int INF = 1e9;
    const size_t N = adjMatrix.size();
    std::vector<bool> visited(N);
    std::vector<int> min_edge(N, INF);
    std::vector<int> best_edge(N);

    min_edge[0] = 0;
    for (int node = 0; node < N; ++node)
    {
        int v = -1;
        for (int u = 0; u < N; ++u)
            if (!visited[u] && (v == -1 || min_edge[u] < min_edge[v]))
                v = u;
        visited[v] = true;

        if (v != 0)
            std::cout << v << " " << best_edge[v] << " " << "[" << adjMatrix[v][best_edge[v]] << "]" << "\n";

        for (int to = 0; to < N; ++to)
        {
            if (adjMatrix[v][to] > 0 && adjMatrix[v][to] < min_edge[to])
            {
                min_edge[to] = adjMatrix[v][to];
                best_edge[to] = v;
            }
        }
    }
}