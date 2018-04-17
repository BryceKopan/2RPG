#ifndef BOUNDING_BOX_H
#define BOUNDING_BOX_H

class BoundingBox
{
    public:
        int x, y, xMax, yMax;

        BoundingBox(int x, int y, int width, int height);

        bool intersects(BoundingBox bbox);
};

#endif
