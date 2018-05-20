#include "Vector2.h"

#include <math.h>

Vector2::Vector2(double x, double y)
{
    this->x = x;
    this->y = y;
}

void Vector2::setPolarCoordinates(double magnitude, int angle)
{
    x = magnitude * cos(angle);
    y = magnitude * sin(angle);
}

double Vector2::getMagnitude()
{
    return sqrtf(x * x + y * y);
}

void Vector2::normalize()
{
    double magnitude = getMagnitude();

    x = x / magnitude;
    y = y / magnitude;
}

Vector2 Vector2::operator+(const Vector2& rhs)
{
    return Vector2(x + rhs.x, y + rhs.y);
}

Vector2 Vector2::operator-(const Vector2& rhs)
{
    return Vector2(x - rhs.x, y - rhs.y);
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
