#pragma once

#define OLC_PGE_APPLICATION
#include<olcPixelGameEngine.h>
#include<GrahamScan.h>

class VisualizerConvexHull : public olc::PixelGameEngine
{
public:
    VisualizerConvexHull(const std::vector<point2d>& points) : mPoints(points)
    {
        sAppName = "Convex hull";
    }

private:
    std::vector<point2d> mPoints;
    std::vector<point2d> ch;

public:
    bool OnUserCreate() override
    {
        ch = grahamScan(mPoints);
        return true;
    }

    bool OnUserUpdate(float fElapsedTime) override
    {

        Clear(olc::BLACK);

        //Рисуем точки
        for (int i = 0; i < mPoints.size(); ++i)
            FillCircle(mPoints[i].x, mPoints[i].y, 2, olc::GREEN);

        //Рисуем оболочку
        for (int i = 0; i < ch.size() - 1; ++i)
            DrawLine(ch[i].x, ch[i].y, ch[i + 1].x, ch[i + 1].y, olc::WHITE);
        DrawLine(ch[ch.size() - 1].x, ch[ch.size() - 1].y, ch[0].x, ch[0].y, olc::WHITE);

        //Координаты мыши
        olc::vi2d vMouse = {GetMouseX(), GetMouseY()};
        DrawString(4, 4, "Mouse: " + std::to_string(vMouse.x) + ", " + std::to_string(vMouse.y));
        return true;
    }

    void showConvexHull()
    {
        for (int i = 0; i < ch.size(); ++i)
            std::cout << ch[i].x << " " << ch[i].y << "\n";
    }
};