#ifndef POLYGON_H
#define POLYGON_H

#include <math.h>
#include <vector>

#include "Point.h"

class Polygon
{
    public:
        Point center;
        std::vector<Point> vertices;

        Polygon(){};
        Polygon(std::vector<Point> vertices);
        Polygon(Point center, std::vector<Point> vertices);

        void rotate(int angle);

        //TODO remove
        void draw();
};

#endif
