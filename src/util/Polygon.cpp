#include "Polygon.h"

//TODO remove
#include <allegro5/allegro_primitives.h>

Polygon::Polygon(std::vector<Point> vertices)
{
    this->center = Point(0, 0);
    this->vertices = vertices;
}

Polygon::Polygon(Point center, std::vector<Point> vertices)
{
    this->center = center;
    this->vertices = vertices;
}

void Polygon::rotate(int angle)
{
    double cs = cos(angle * M_PI/180);
    double sn = sin(angle * M_PI/180);

    for(int i = 0; i < vertices.size(); i++)
    {
        double tempX = vertices[i].x * cs - vertices[i].y * sn;
        double tempY = vertices[i].x * sn + vertices[i].y * cs;

        vertices[i].x = tempX;
        vertices[i].y = tempY;
    }
}

//TODO remove
void Polygon::draw()
{
    ALLEGRO_COLOR red = al_map_rgb(255, 0, 0);

    for(int i = 0; i < vertices.size(); i++)
    {
        Point p1 = vertices[i];
        Point p2 = vertices[i + 1 == vertices.size() ? 0 : i + 1];
        p1 += center;
        p2 += center;

        al_draw_line(p1.x, p1.y, p2.x, p2.y, red, 1);
    }
}
