#ifndef VECTOR_2
#define VECTOR_2

class Vector2 
{
    public:
        double x = 0, y = 0;

        Vector2(){};
        Vector2(double x, double y);

        void setPolarCoordinates(double magnitude, int angle);
        double getMagnitude();
        void normalize();

        Vector2 operator+(const Vector2& rhs);
        Vector2 operator-(const Vector2& rhs);
        Vector2 operator+=(const Vector2& rhs);
        Vector2 operator-=(const Vector2& rhs);
    private:
};

#endif
