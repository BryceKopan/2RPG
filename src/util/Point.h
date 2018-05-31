#ifndef POINT_H
#define POINT_H

class Point
{
    public:
        Point(){};
        Point(double x, double y)
        {
            this->x = x;
            this->y = y;
        };

    private:
        double x = 0, y = 0;
};

#endif
