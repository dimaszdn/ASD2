#include<VisualizerConvexHull.h>

int main()
{
    std::vector<point2d> points = {
            {100, 100},
            {150, 70},
            {130, 150},
            {200, 125},
            {200, 165},
            {380, 165},
            {100, 350},
            {100, 200}
    };

    VisualizerConvexHull demo(points);
    if (demo.Construct(400, 400, 2, 2))
    {
        demo.Start();
        demo.showConvexHull();
    }

    return 0;
}