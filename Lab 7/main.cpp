#include <iostream>

#include<UserInput.h>
#include <Prim.h>

int main()
{
    auto adjMatrix = getMatrixFromFile("files/input2.txt");
    prim(adjMatrix);
    return 0;
}