#include "Polygon.h"

//TODO remove
#include <allegro5/allegro_primitives.h>

Polygon::Polygon(Point center, std::vector<Point> points)
{
    this->center = center;
    this->points = points;
}

void Polygon::rotate(int angle)
{
    double cs = cos(angle * M_PI/180);
    double sn = sin(angle * M_PI/180);

    for(int i = 0; i < points.size(); i++)
    {
        double tempX = points[i].x * cs - points[i].y * sn;
        double tempY = points[i].x * sn + points[i].y * cs;

        points[i].x = tempX;
        points[i].y = tempY;
    }
}

//TODO remove
void Polygon::draw()
{
    Point p1 = points[points.size() - 1] + center;
    ALLEGRO_COLOR red = al_map_rgb(255, 0, 0);

    for(int i = 0; i < points.size(); i++)
    {
        Point p2 = points[i] + center;

        al_draw_line(p1.x, p1.y, p2.x, p2.y, red, 1);

        p1 = p2;
    }
}
