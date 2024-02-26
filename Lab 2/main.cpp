#include <iostream>
#include<Func.h>

template<typename T>
void showMatrix(const std::vector<std::vector<T>>& matrix)
{
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix[i].size(); ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

/*Если нету у узла соседей, то крашит, учесть это*/

int main()
{
    std::vector<std::vector<bool>> adjMatrix = getMatrixFromFile("input.txt");
    int start = 2;
    for (int i = 0; i < adjMatrix.size(); ++i)
    {
        std::cout << "Paths for node = " << i + 1 << "\n";
        for (int j = 0; j < adjMatrix[i].size(); ++j)
        {
            if (j + 1 != i + 1)
            {
                shortWay(BFS(adjMatrix, i + 1, j + 1), j + 1);
                std::cout << "\n";
            }
        }
        std::cout << "###############################" << "\n";
    }
    return 0;
}
