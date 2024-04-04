#include <iostream>

#include <Graph.h>

int main()
{
    try
    {
        Graph graph("files/input.txt");
        graph.findScc();
        graph.showSccAndCount();
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << "\n";
    }
    return 0;
}
