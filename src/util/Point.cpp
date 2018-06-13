#include "Point.h"

Point Point::operator+(const Point& rhs) const
{
    return Point(x + rhs.x, y + rhs.y);
}

Point Point::operator-(const Point& rhs) const
{
    return Point(x - rhs.x, y - rhs.y);
}

Point Point::operator+=(const Point& rhs)
{
    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
}

Point Point::operator-=(const Point& rhs)
{
    this->x -= rhs.x;
    this->y -= rhs.y;
    return *this;
}

Point Point::operator+(const Vector2& rhs) const
{
    return Point(x + rhs.x, y + rhs.y);
}

Point Point::operator-(const Vector2& rhs) const
{
    return Point(x - rhs.x, y - rhs.y);
}

Point Point::operator+=(const Vector2& rhs)
{
    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
}

Point Point::operator-=(const Vector2& rhs)
{
    this->x -= rhs.x;
    this->y -= rhs.y;
    return *this;
}
