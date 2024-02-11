#pragma once

struct point2d
{
    int x, y;
};

struct vector2d
{
    int x, y;

    vector2d(point2d a, point2d b)
    {
        x = b.x - a.x;
        y = b.y - a.y;
    }
};

int cross(vector2d a, vector2d b)
{
    return a.x * b.y - b.x * a.y;
    /*
     * |a_x b_x|
     * |a_y b_y|
     * */
}

std::vector<point2d> grahamScan(std::vector<point2d> points)
{
    //ищем опорную точку
    for (int i = 1; i < points.size(); ++i)
    {
        if ((points[i].x < points[0].x) ||
            (points[i].x == points[0].x && points[i].y < points[0].y))
            std::swap(points[0], points[i]);
    }

    //сортируем точки
    for (int i = 1; i < points.size(); ++i)
    {
        for (int j = 1; j < points.size(); ++j)
        {
            if (cross(vector2d(points[0], points[i]), vector2d(points[0], points[j])) > 0)
                std::swap(points[i], points[j]);
        }
    }

    //убираем не нужные точки
    std::vector<point2d> ch = {points[0], points[1]};
    for (int i = 2; i < points.size(); ++i)
    {
        while (cross(vector2d(ch[ch.size() - 2], ch[ch.size() - 1]), vector2d(ch[ch.size() - 1], points[i])) < 0)
            ch.pop_back();
        ch.push_back(points[i]);
    }

    return ch;
}