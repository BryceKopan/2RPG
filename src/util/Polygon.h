#ifndef POLYGON_H
#define POLYGON_H

#include <math.h>
#include <vector>

#include "Point.h"

class Polygon
{
    public:
        Point center;
        std::vector<Point> points;

        Polygon(){};
        Polygon(Point center, std::vector<Point> points);

        void rotate(int angle);

        //TODO remove
        void draw();
};

#endif
