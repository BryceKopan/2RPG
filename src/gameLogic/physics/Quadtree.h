#ifndef QUADTREE_H
#define QUADTREE_H

#include <vector>

#include "../../util/Point.h"
class AABB
{
    Point center;
    double halfWidth, halfHeight;

    AABB():
        center(), width(), height(){};
    AABB(Point center, int width, int height): 
        center(center), halfWidth(width/2), halfHeight(height/2){};

    bool contains(Point p) const;
    {
        if(p.x < center.x - )
    }
};
#endif
