#pragma once

#include<vector>
#include<queue>
#include<iostream>

std::vector<int> bfs_search(const std::vector<std::vector<bool>>& adjMatrix, int start)
{
    std::vector<int> distance(adjMatrix.size(), - 1);
    std::vector<int> parents(adjMatrix.size());
    std::queue<int> searchQueue;

    searchQueue.push(start - 1);
    distance[start - 1] = 0;
    while (!searchQueue.empty())
    {
        int curNode = searchQueue.front();
        searchQueue.pop();
        for (int nextNode = 0; nextNode < adjMatrix[curNode].size(); ++nextNode)
        {
            if (adjMatrix[curNode][nextNode] == 1 && distance[nextNode] == -1)
            {
                searchQueue.push(nextNode);
                distance[nextNode] = distance[curNode] + 1;
                parents[nextNode] = curNode;
            }
        }
    }

    /*for (int i = 0; i < adjMatrix.size(); ++i)
        std::cout << i << " ";
    std::cout << "\n";
    for (auto el : parents)
        std::cout << el << " ";*/

    return parents;
}

bool vectorIsNull(const std::vector<int>& vec)
{
    for (auto el : vec)
    {
        if (el != 0)
            return false;
    }
    return true;
}

void showShortPath (const std::vector<int>& parents, int start, int finish)
{
    if (vectorIsNull(parents))
        return;

    int a = start - 1;
    int b = finish - 1;
    std::cout << b + 1;
    while (b != a)
    {
        b = parents[b];
        std::cout << " <-- " << b + 1;
    }
    std::cout << "\n";
}

