#include "BoundingBox.h"

BoundingBox::BoundingBox(int x, int y, int width, int height)
{
    this->x = x;
    this->y = y;
    this->xMax = x + width;
    this->yMax = y + height;
}

bool BoundingBox::intersects(BoundingBox bbox)
{
    if(x < bbox.xMax && xMax > bbox.x &&
            y < bbox.yMax && yMax > bbox.y)
        return true;

    return false;
}
