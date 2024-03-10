#pragma once

#include<vector>
#include<queue>
#include<iostream>

void bfs_search(const std::vector<std::vector<bool>>& adjMatrix, std::vector<int>& distance, int start)
{
    std::queue<int> searchQueue;

    searchQueue.push(start - 1);
    distance[start - 1] = 0;
    while (!searchQueue.empty())
    {
        int curNode = searchQueue.front();
        searchQueue.pop();
        std::cout << curNode + 1 << " "; //вывод элементов компоненты связности
        for (int nextNode = 0; nextNode < adjMatrix[curNode].size(); ++nextNode)
        {
            if (adjMatrix[curNode][nextNode] == 1 && distance[nextNode] == -1)
            {
                searchQueue.push(nextNode);
                distance[nextNode] = distance[curNode] + 1;
            }
        }
    }
    std::cout << "\n";
}

void countComponents(const std::vector<std::vector<bool>>& adjMatrix)
{
    if (adjMatrix.empty())
        std::cout << "Number of components: " << 0 << "\n";

    int counter = 1;
    std::vector<int> distance(adjMatrix.size(), -1);
    bfs_search(adjMatrix, distance, 1);
    for (int i = 0; i < distance.size(); ++i)
    {
        if (distance[i] == -1)
        {
            ++counter;
            bfs_search(adjMatrix, distance, i + 1);
        }
    }
    std::cout << "Number of components: " << counter << "\n";
}