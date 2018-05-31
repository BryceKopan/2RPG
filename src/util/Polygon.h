#ifndef POLYGON_H
#define POLYGON_H

#include <math.h>

#include "Point.h"

class Polygon
{
    public:
        Point center;
        Point points[];

        void rotate(int angle)
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
        };
}

#endif
