#ifndef POINT_H
#define POINT_H

class Point
{
    public:
        double x = 0, y = 0;

        Point(){};
        Point(double x, double y)
        {
            this->x = x;
            this->y = y;
        };
};

#endif
