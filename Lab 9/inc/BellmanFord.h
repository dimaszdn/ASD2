#pragma once

#include<vector>
#include<Edge.h>

//списком рёбер просто удобнее
std::vector<int> bellmanFord(const size_t N, const std::vector<Edge>& edges, std::vector<int>& dist, int start)
{
    const int INF = 1e9;
    dist.resize(N);
    std::fill(dist.begin(), dist.end(), INF);
    std::vector<int> from(N, -1);
    dist[start] = 0;

    for (int i = 0; i < N - 1; ++i)
    {
        for (auto &[begin, end, weight] : edges)
        {
            if (dist[begin] != INF && dist[end] > dist[begin] + weight)
            {
                dist[end] = dist[begin] + weight;
                from[end] = begin;
            }
        }
    }

    return from;
}

std::vector<int> getPath(const std::vector<int>& from, int start, int finish)
{
    std::vector<int> path;
    for (int v = finish; v != -1; v = from[v])
        path.push_back(v);

    if (path.size() == 1)
    {
        if (start == finish)
            path.push_back(finish);
        else
            path.push_back(start);
    }
    std::reverse(path.begin(), path.end());
    return path;
}

void showPath(const std::vector<int>& path)
{
    for (auto n : path)
        std::cout << n << " ";
}

/*
//если через матрицу смежности
std::vector<int> bellmanFord(const std::vector<std::vector<int>>& adjMatrix, std::vector<int>& dist,
                             int start)
{
    const int INF = 1e9;
    dist.resize(adjMatrix.size());
    std::fill(dist.begin(), dist.end(), INF);
    std::vector<int> from(adjMatrix.size(), -1);
    dist[start] = 0;

    for (int i = 0; i < adjMatrix.size() - 1; ++i)
    {
        for (int y = 0; y < adjMatrix.size(); ++y)
        {
            for (int x = 0; x < adjMatrix.size(); ++x)
            {
                if (adjMatrix[y][x] != 0)
                {
                    if (dist[y] != INF && dist[x] > dist[y] + adjMatrix[y][x])
                    {
                        dist[x] = dist[y] + adjMatrix[y][x];
                        from[x] = y;
                    }
                }
            }
        }
    }

    return from;
}
*/