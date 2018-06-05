#include "SATCollision.h"

bool SATCollision::intersect(const Polygon* poly1, 
        const Polygon* poly2)
{
    VectorVector axes1 = getAxes(poly1);
    VectorVector axes2 = getAxes(poly2);
    axes1.insert(axes1.end(), axes2.begin(), axes2.end());
    VectorVector axes = removeParallels(axes1);

    for(int i = 0; i < axes.size(); i++)
    {
        Vector2 axis = axes[i];

        Projection p1 = getProjection(poly1, axis);
        Projection p2 = getProjection(poly2, axis);

        if(std::get<1>(p1) < std::get<0>(p2) || 
                std::get<1>(p2) < std::get<0>(p1))
            return false;
    }

    return true;
}

VectorVector SATCollision::getAxes(const Polygon* poly)
{
    std::vector<Point> vertices = poly->vertices;
    VectorVector axes;

    for(int i = 0; i < vertices.size(); i++)
    {
        Point p1 = vertices[i];
        Point p2 = vertices[i + 1 == vertices.size() ? 0 : i + 1];
        Vector2 edge = p1 - p2;
        Vector2 normal = edge.getLeftNormalVector();
        Vector2 unitNormal = normal.getUnitVector();
        axes.push_back(unitNormal);
    }

    return axes;
}

Projection SATCollision::getProjection(const Polygon* poly, 
        Vector2 axis)
{
    double min = axis.dotProduct(poly->vertices[0] + poly->center);
    double max = min;

    for(int i = 0; i < poly->vertices.size(); i++)
    {
        double p = axis.dotProduct(poly->vertices[i] + poly->center);

        if(p < min)
            min = p;
        else if(p > max)
            max = p;
    }

    return std::make_tuple(min, max);
}

VectorVector SATCollision::removeParallels(VectorVector axes)
{
    VectorVector newAxes;

    for(int i = 0; i < axes.size(); i++)
    {
        bool parallel = false;
        
        for(int j = 0; j < newAxes.size(); j++)
        {
            double dot = axes[i].dotProduct(newAxes[j]);
            if(dot == 1 || dot == -1)
            {
                parallel = true;
            }
        }

        if(!parallel)
            newAxes.push_back(axes[i]);
    }

    return newAxes;
}
