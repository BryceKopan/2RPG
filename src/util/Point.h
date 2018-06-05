#ifndef POINT_H
#define POINT_H

class Point
{
    public:
        double x = 0, y = 0;

        Point(){}
        Point(double x, double y) : x(x), y(y) {}
        
        Point operator+(const Point& rhs) const
        {
            return Point(x + rhs.x, y + rhs.y);
        }

        Point operator-(const Point& rhs) const
        {
            return Point(x - rhs.x, y - rhs.y);
        }
        
        Point operator+=(const Point& rhs)
        {
            this->x += rhs.x;
            this->y += rhs.y;
            return *this;
        }

        Point operator-=(const Point& rhs)
        {
            this->x -= rhs.x;
            this->y -= rhs.y;
            return *this;
        }
};

#endif
