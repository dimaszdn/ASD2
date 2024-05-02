#include <iostream>

#include<UserInput.h>
#include<Graph.h>

int main()
{
    try
    {
        auto adjMatrix = getMatrixFromFile("files/input.txt");

        Graph graph(adjMatrix);

        auto cycle = graph.findEulerCycle();
        if (cycle.empty())
            std::cout << "There is no Euler cycle";
        else
        {
            for (auto node : cycle)
                std::cout << node << " ";
            std::cout << "\n";
        }

    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << "\n";
    }
    return 0;
}