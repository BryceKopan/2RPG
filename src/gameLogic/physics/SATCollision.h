#ifndef SAT_COLLISION_H
#define SAT_COLLISION_H

#include <vector>
#include <tuple>

#include "../../util/Polygon.h"
#include "../../util/Vector2.h"

typedef std::tuple<double, double> Projection;

class SATCollision
{
    public:
        static bool intersect(Polygon poly1, Polygon poly2);
    private:
        static std::vector<Vector2> getAxes(Polygon poly);
        static Projection getProjection(Polygon poly, Vector2 axis);
};

#endif
