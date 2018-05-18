#ifndef BOUNDING_BOX_H
#define BOUNDING_BOX_H

class BoundingBox
{
    //Collision based of ints while positions and movement based of double
    public:
        double x, y, width, height, xMax, yMax;

        BoundingBox(){};
        BoundingBox(double x, double y, double width, double height);

        void update(double x, double y);
        bool intersects(BoundingBox bbox);
        void draw();
};

#endif
