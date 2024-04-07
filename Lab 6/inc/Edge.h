#pragma once

#include<fstream>

struct Edge
{
    int begin, end, weight;

    Edge(int begin, int end, int weight)
    {
        this->begin = begin;
        this->end = end;
        this->weight = weight;
    }

    bool operator < (const Edge& other) const
    {
        return this->weight < other.weight;
    }

    friend std::ostream& operator<<(std::ostream& out, Edge& edge)
    {
        out << edge.begin << " " << edge.end << " " << edge.weight;
        return out;
    }
};