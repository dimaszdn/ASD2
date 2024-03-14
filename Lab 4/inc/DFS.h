#pragma once

#include<vector>
#include<stack>
#include<iostream>

void path_to(const std::vector<int>& parents, int start, int finish)
{
    --start; --finish;
    std::cout << finish + 1;
    while (finish != start)
    {
        finish = parents[finish];
        std::cout << " <-- " << finish + 1;
    }
    std::cout << "\n";
}

//реализация через стек
void dfs_search(const std::vector<std::vector<bool>>& adjMatrix,
                               std::vector<bool>& visited,
                               int start)
{
    std::stack<int> searchStack;
    std::vector<int> parents(adjMatrix.size());

    searchStack.push(start - 1);
    visited[start - 1] = true;
    while (!searchStack.empty())
    {
        int curNode = searchStack.top();
        searchStack.pop();
        std::cout << curNode + 1 << " "; //выводим элемент компоненты
        for (int nextNode = 0; nextNode < adjMatrix[curNode].size(); ++nextNode)
        {
            if (!visited[nextNode] && adjMatrix[curNode][nextNode] == 1)
            {
                searchStack.push(nextNode);
                visited[nextNode] = true;
                parents[nextNode] = curNode;
            }
        }
    }
    std::cout << "\n";
//    return parents;
}

void countComponents(const std::vector<std::vector<bool>>& adjMatrix)
{
    std::vector<bool> visited(adjMatrix.size());
    int counter = 0;
    for (int node = 0; node < visited.size(); ++node)
    {
        if (!visited[node])
        {
            ++counter;
            dfs_search(adjMatrix, visited, node + 1);
        }
    }
    std::cout << "Number of components: " << counter << "\n";
}