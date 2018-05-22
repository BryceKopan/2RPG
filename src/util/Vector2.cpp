#include "Vector2.h"

#include <cmath>
#include <stdio.h>

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

void Vector2::normalize()
{
    double magnitude = getMagnitude();

    if(magnitude != 0)
    {
        x = x / magnitude;
        y = y / magnitude;
    }
}

double Vector2::getMagnitude()
{
    return sqrtf(x * x + y * y);
}

double Vector2::getNormalX()
{
    double magnitude = getMagnitude();

    if(magnitude = 0)
        return 0;
    else
        return x / getMagnitude();
}

double Vector2::getNormalY()
{
    double magnitude = getMagnitude();

    if(magnitude = 0)
        return 0;
    else
        return y / getMagnitude();
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
