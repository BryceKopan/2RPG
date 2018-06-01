#ifndef VECTOR_2
#define VECTOR_2

#include "Point.h"

class Vector2 
{
    public:
        double x = 0, y = 0;

        Vector2(){};
        Vector2(Point p);
        Vector2(double x, double y);

        void setPolarCoordinates(double magnitude, int angle);
        double getMagnitude();
        Vector2 getUnitVector();
        Vector2 getLeftNormalVector();
        Vector2 getRightNormalVector();

        Vector2 operator+(const Vector2& rhs);
        Vector2 operator-(const Vector2& rhs);
        Vector2 operator-();
        Vector2 operator+=(const Vector2& rhs);
        Vector2 operator-=(const Vector2& rhs);
};

#endif
