#include "SATCollision.h"

bool SATCollision::intersect(Polygon poly1, Polygon poy2)
{
    
}

std::vector<Vector2> SATCollision::getAxes(Polygon poly)
{
    std::vector<Point> vertices = poly.vertices;
    std::vector<Vector2> axes;

    for(int i = 0; i < vertices.size(); i++)
    {
        Point p1 = vertices[i];
        Point p2 = vertices[i + 1 == vertices.size() ? 0 : i + 1];
        Vector2 edge = p1 - p2;
        Vector2 normal = edge.getLeftNormalVector();
        Vector2 unitNormal = normal.getUnitVector();
        axes.push_back(unitNormal);
    }

    for(int i = 0; i < axes.size(); i++)
    {
        for(int j = 0; j < axes.size(); j++)
        {
            if(i != j && axes[i].dotProduct(axes[j]) == 1)
            {
                axes.erase(axes.begin() + j);
                i--;
                j--;
            }
        }
    }

    return axes;
}

Projection SATCollision::getProjection(Polygon poly, Vector2 axis)
{
}
