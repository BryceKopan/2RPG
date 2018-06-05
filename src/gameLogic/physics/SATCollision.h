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
        static bool intersect(const Polygon* poly1, 
                const Polygon* poly2);
        static Projection getProjection(const Polygon* poly, 
                Vector2 axis);
    private:
        static VectorVector getAxes(const Polygon* poly);
        static VectorVector removeParallels(VectorVector axes);
};

#endif
