#pragma once

#include<string>
#include<set>
#include<map>

template <typename Container, typename T>
bool contains(const Container& container, const T& value)
{
    return container.find(value) != container.end();
}

std::map<char, int> getOffsetTable(const std::string& subStr)
{
    std::set<char> set;
    std::map<char, int> table; //для элемента будем указывать его смещение
    //начинаем с предпоследнего
    for (int i = subStr.size() - 2; i >= 0; --i)
    {
        if (!contains(set, subStr[i]))
        {
            //смещение это номер при нумерации с конца
            table[subStr[i]] = subStr.size() - i - 1;
            set.insert(subStr[i]);
        }
    }
    //отдельно рассматриваем последний элемент
    if (!contains(set, subStr[subStr.size() - 1]))
        table[subStr[subStr.size() - 1]] = subStr.size();
    table['*'] = subStr.size(); //отвечает за смещения прочих элементов

    return table;
}

int boyerMoore(const std::string& str, const std::string& subStr)
{
    auto table = getOffsetTable(subStr);
    int i = subStr.size() - 1;
    int k, off;
    while (i < str.size())
    {
        k = 0;
        for (int j = subStr.size() - 1; j >= 0; --j)
        {
            if (subStr[j] != str[i - k])
            {
                //если последний символ в образе
                if (j == subStr.size() - 1)
                    off = !contains(table, str[i]) ? table['*'] : table[str[i]];
                else
                    off = table[subStr[j]];

                i += off;
                break;
            }
            k++;
            if (j == 0)
                return i - k + 1;
        }
    }
    return -1;
}