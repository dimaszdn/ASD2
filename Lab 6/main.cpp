#include <iostream>

#include<Func.h>
#include<Graph.h>

int main()
{
    try
    {
        std::vector<std::vector<int>> adjMatrix = getMatrixFromFile("files/input2.txt");
        Graph graph(adjMatrix.size());
        fillGraph(adjMatrix, graph);
        auto vec = graph.kruskal();
        for (auto edge : vec)
            std::cout << edge << "\n";
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << "\n";
    }

    return 0;
}