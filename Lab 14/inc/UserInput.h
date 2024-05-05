#pragma once

#include<string>
#include<fstream>

std::string getStringFromFile(const std::string& path)
{
    std::ifstream fin(path);
    std::string input{};
    if (!fin.is_open())
        throw std::exception("The file could not be opened!");
    else
        std::getline(fin, input);
    return input;
}

std::string getSubStrFromConsole()
{
    std::string s;
    std::cout << "Enter a substring: ";
    std::cin >> s;
    return s;
}