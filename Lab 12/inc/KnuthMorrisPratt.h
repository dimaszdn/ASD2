#pragma once

#include<vector>
#include<string>

std::vector<int> getPrefixFunc(const std::string& subStr)
{
    std::vector<int> p(subStr.size(), 0);
    int j = 0, i = 1;
    while (i < subStr.size())
    {
        if (subStr[i] != subStr[j])
        {
            if (j == 0)
            {
                p[i] = 0;
                i++;
            }
            else
                j = p[j - 1];
        }
        else
        {
            p[i] = j + 1;
            i++;
            j++;
        }

    }
    return p;
}

int knuthMorrisPratt(const std::string& str, const std::string& subStr)
{
    auto p = getPrefixFunc(subStr);
    int i = 0, j = 0;
    while (i < str.size())
    {
        if (str[i] == subStr[j])
        {
            i++;
            j++;
            if (j == subStr.size())
                return i - j;
        }
        else
        {
            if (j > 0)
                j = p[j - 1];
            else
                i++;
        }
    }
    return -1;
}