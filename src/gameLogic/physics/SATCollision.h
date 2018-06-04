#ifndef SAT_COLLISION_H
#define SAT_COLLISION_H

#include <vector>
#include <tuple>

#include "../../util/Polygon.h"
#include "../../util/Vector2.h"

typedef std::tuple<double, double> Projection;
typedef std::vector<Vector2> VectorVector;

class SATCollision
{
    public:
        static bool intersect(Polygon poly1, Polygon poly2);
    private:
        static VectorVector getAxes(Polygon poly);
        static Projection getProjection(Polygon poly, Vector2 axis);
        static VectorVector removeParallels(VectorVector axes);
};

#endif
