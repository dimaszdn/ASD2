#include <iostream>

#include<UserInput.h>
#include<Dijkstra.h>

int main()
{
    try
    {
        auto adjMatrix = getMatrixFromFile("files/input.txt");

        std::vector<int> from;
        std::vector<int> dist;
        for (int i = 0; i < adjMatrix.size(); ++i)
        {
            from = dijkstra(adjMatrix, dist, i);
            std::cout << "For node " << i << ":" << "\n";
            for (int j = 0; j < adjMatrix.size(); ++j)
            {
                showPath(getPath(from,i, j));
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