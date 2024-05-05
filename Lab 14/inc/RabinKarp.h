#pragma once

const auto x = 31;
int q = pow(2, 31) - 1;

int code(char c)
{
    return static_cast<int>(c);
}

int gornerScheme(const std::string& str)
{
    int result = code(str[0]);
    for (int i = 0; i < str.size() - 1; ++i)
        result = result * x + code(str[i + 1]);
    return result;
}

int hash(const std::string& str)
{
    return gornerScheme(str) % q;
}

int searchSubstr(const std::string& str, const std::string& substr)
{
    size_t m = substr.size();
    std::string curPart = str.substr(0, m);
    int subHash = hash(substr);
    int curHash = hash(curPart);

    int multiplier = pow(x, m - 1);

    for (int i = 0; i <= str.size() - m; ++i)
    {
        if (subHash == curHash)
        {
            curPart = str.substr(i, m);
            if (substr == curPart)
                return i;
        }
        curHash = ((curHash - code(str[i]) * multiplier) * x + code(str[i + m])) % q;
    }
    return -1;
}