#include <iostream>

#include <Graph.h>

int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 6);
    g.addEdge(1, 0);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(2, 3);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.addEdge(3, 1);
    g.addEdge(3, 2);
    g.addEdge(3, 4);
    g.addEdge(3, 6);
    g.addEdge(4, 3);
    g.addEdge(4, 5);
    g.addEdge(5, 4);
    g.addEdge(5, 2);
    g.addEdge(6, 0);
    g.addEdge(6, 2);
    g.addEdge(6, 3);
    auto colors = g.colorize();
    for (int i = 0; i < colors.size(); ++i)
        std::cout << colors[i] << " ";
    std::cout << "\n";
    return 0;
}