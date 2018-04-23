#ifndef BOUNDING_BOX_H
#define BOUNDING_BOX_H

class BoundingBox
{
    public:
        int x, y, width, height, xMax, yMax;

        BoundingBox(){};
        BoundingBox(int x, int y, int width, int height);

        void update(int x, int y);
        bool intersects(BoundingBox bbox);
        void draw();
};

#endif
