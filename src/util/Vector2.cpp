#include "Vector2.h"

#include <cmath>
#include <stdio.h>

Vector2::Vector2(Point p)
{
    this->x = p.x;
    this->y = p.y;
}

Vector2::Vector2(double x, double y)
{
    this->x = x;
    this->y = y;
}

void Vector2::setPolarCoordinates(double magnitude, int angle)
{
    x = magnitude * cos(angle * M_PI / 180);
    y = magnitude * sin(angle * M_PI / 180);
}

double Vector2::getMagnitude()
{
    return sqrtf(x * x + y * y);
}

Vector2 Vector2::getUnitVector()
{
    double magnitude = getMagnitude();

    if(magnitude != 0)
        return Vector2(x / magnitude, y / magnitude);
    else
        return Vector2(0, 0);
}

Vector2 Vector2::getLeftNormalVector()
{
    return Vector2(-x, y);
}

Vector2 Vector2::getRightNormalVector()
{
    return Vector2(x, -y);
}

Vector2 Vector2::operator+(const Vector2& rhs)
{
    return Vector2(x + rhs.x, y + rhs.y);
}

Vector2 Vector2::operator-(const Vector2& rhs)
{
    return Vector2(x - rhs.x, y - rhs.y);
}

Vector2 Vector2::operator-()
{
    return Vector2(-x, -y);
}

Vector2 Vector2::operator+=(const Vector2& rhs)
{
    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
}

Vector2 Vector2::operator-=(const Vector2& rhs)
{
    this->x -= rhs.x;
    this->y -= rhs.y;
    return *this;
}
