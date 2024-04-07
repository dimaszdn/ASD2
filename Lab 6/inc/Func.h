#pragma once

#include<vector>
#include<string>
#include<sstream>
#include<fstream>

std::vector<int> convertToRowMatrix(const std::string& row)
{
    std::vector<int> rowMatrix;
    std::istringstream is(row);
    int value;
    while(is >> value)
        rowMatrix.push_back(value);
    return rowMatrix;
}

std::vector<std::vector<int>> getMatrixFromFile(const std::string& path)
{
    std::vector<std::vector<int>> matrix;
    std::ifstream file(path);
    if (!file.is_open())
        throw std::exception("File opening error");
    else
    {
        std::string row;
        while (std::getline(file, row))
            matrix.push_back(convertToRowMatrix(row));
    }
    return matrix;
}

void print(const std::vector<std::vector<int>>& matrix)
{
    std::cout << "   ";
    for (int i = 0; i < matrix.size(); ++i)
        std::cout << i << "  ";
    std::cout << "\n";
    for (int i = 0; i < matrix.size(); ++i)
    {
        std::cout << i << "  ";
        for (int j = 0; j < matrix[i].size(); ++j)
            std::cout << matrix[i][j] << "  ";
        std::cout << "\n";
    }
}