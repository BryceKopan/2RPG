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
        
        Point operator+(const Point& rhs)
        {
            return Point(x + rhs.x, y + rhs.y);
        }

        Point operator-(const Point& rhs)
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
