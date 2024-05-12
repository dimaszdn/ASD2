#pragma once

#include<vector>
#include<string>

class FiniteAutomaton
{
private:
    std::vector<std::vector<int>> trTable{}; //таблица переходов
    const int ASCII_size = 256;
    int finalState{};

public:
    explicit FiniteAutomaton(const std::string& substr)
    {
        trTable.resize(substr.size() + 1, std::vector<int>(ASCII_size, 0));
        trTable[0][substr[0]] = 1;
        for (int state = 1; state < substr.size(); ++state)
        {
            for (int c = 0; c < ASCII_size; ++c)
            {
                int prev = trTable[state - 1][c];
                trTable[state][c] = trTable[prev][c];
            }
            trTable[state][substr[state]] = state + 1;
        }
        finalState = substr.size();
    }

    int searchIn(const std::string& str)
    {
        int state = 0;
        for (int i = 0; i < str.size(); ++i)
        {
            state = trTable[state][str[i]];
            if (state == finalState)
                return i - finalState + 1;
        }
        return -1;
    }
};