#ifndef POINT_H
#define POINT_H

#include "Vector2.h"

class Vector2;

class Point
{
    public:
        double x = 0, y = 0;

        Point(){}
        Point(double x, double y) : x(x), y(y) {}
        
        Point operator+(const Point& rhs) const;
        Point operator-(const Point& rhs) const;
        Point operator+=(const Point& rhs);
        Point operator-=(const Point& rhs);

        Point operator+(const Vector2& rhs) const;
        Point operator-(const Vector2& rhs) const;
        Point operator+=(const Vector2& rhs);
        Point operator-=(const Vector2& rhs);
};

#endif
