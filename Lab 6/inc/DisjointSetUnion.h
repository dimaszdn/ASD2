#pragma once

#include<vector>

struct Union
{
    std::vector<int> parents;

    explicit Union(size_t count) : parents(count)
    {
        for (int i = 0; i < count; ++i)
            parents[i] = i;
    }

    int leader(int node)
    {
        if (parents[node] == node)
            return node;
        else
            return leader(parents[node]);
    }

    void unite(int u, int v)
    {
        u = leader(u);
        v = leader(v);
        parents[u] = v;
    }
};