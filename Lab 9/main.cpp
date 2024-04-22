#include<iostream>

#include<UserInput.h>
#include <BellmanFord.h>

int main()
{
    try
    {
        auto adjMatrix = getMatrixFromFile("files/input.txt");
        //заполнение списка рёбер
        std::vector<Edge> edges;
        for (int i = 0; i < adjMatrix.size(); ++i)
            for (int j = 0; j < adjMatrix.size(); ++j)
                if (adjMatrix[i][j] != 0)
                    edges.emplace_back(i, j, adjMatrix[i][j]);

        //вывод кратчайших путей
        std::vector<int> dist;
        std::vector<int> from;
        for (int i = 0; i < adjMatrix.size(); ++i)
        {
            from = bellmanFord(adjMatrix.size(), edges, dist, i);
            std::cout << "For node " << i << ":" << "\n";
            for (int j = 0; j < adjMatrix.size(); ++j)
            {
                showPath(getPath(from,i, j));
                if (dist[j] == 1e9)
                    std::cout << "[" << "INF" << "]" << "\n";
                else
                    std::cout << "[" << dist[j] << "]" << "\n";
            }
            std::cout << "\n";
        }
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << "\n";
    }
    return 0;
}