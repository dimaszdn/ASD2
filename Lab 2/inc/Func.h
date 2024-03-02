#pragma once

#include<vector>
#include<sstream>
#include<fstream>

//вспомогательная функция для getMatrixFromFile
std::vector<bool> convertToRowMatrix(const std::string& row)
{
    std::vector<bool> rowMatrix;
    std::istringstream is(row);
    bool value;
    while(is >> value)
        rowMatrix.push_back(value);
    return rowMatrix;
}

std::vector<std::vector<bool>> getMatrixFromFile(const std::string& path)
{
    std::vector<std::vector<bool>> matrix;
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