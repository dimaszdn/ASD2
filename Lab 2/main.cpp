#include<Func.h>
#include<BFS.h>

#include <iostream>

int main()
{
    try
    {
        std::vector<std::vector<bool>> adjMatrix = getMatrixFromFile("input2.txt");
        for (int i = 0; i < adjMatrix.size(); ++i)
        {
            std::cout << "[" << "Paths for node " << i + 1 << "]" << "\n";
            std::vector<int> parents = bfs_search(adjMatrix, i + 1);

            for (int j = 0; j < adjMatrix.size(); ++j)
            {
                if (j + 1 == i + 1)
                    continue;

                showShortPath(parents, i + 1, j + 1);
            }
            std::cout << "###################################" << "\n";
        }
    }
    catch (const std::exception& ex) { std::cout << ex.what() << "\n"; }

    return 0;
}
