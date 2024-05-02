#include <iostream>

#include<UserInput.h>
#include<KnuthMorrisPratt.h>

int main()
{
    //cdbda
    try
    {
        std::string str = getStringFromFile("files/input.txt");
        std::string subStr = getSubStrFromConsole();

        int index = knuthMorrisPratt(str, subStr);
        if (index == -1)
            std::cout << "The substring not found!" << "\n";
        else
            std::cout << "The substring starts with the index " << "[" << index << "]" << "\n";
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << "\n";
    }
    return 0;
}