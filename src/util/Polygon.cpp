#include "Polygon.h"

Polygon::Polygon(Point center, std::vector<Point> points)
{
    this->center = center;
    this->points = points;
}

void Polygon::rotate(int angle)
{
    double cs = cos(angle * M_PI/180);
    double sn = sin(angle * M_PI/180);

    for(int i = 0; i < points.size(); i++)
    {
        double tempX = points[i].x * cs - points[i].y * sn;
        double tempY = points[i].x * sn + points[i].y * cs;

        points[i].x = tempX;
        points[i].y = tempY;
    }
}
