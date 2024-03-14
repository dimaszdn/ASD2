#include <iostream>
#include<vector>

#include <Func.h>
#include<DFS.h>

int main()
{
    try
    {
        std::vector<std::vector<bool>> adjMatrix = getMatrixFromFile("input2.txt");
        countComponents(adjMatrix);
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << "\n";
    }

    return 0;
}