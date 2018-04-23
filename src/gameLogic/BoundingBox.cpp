#include "BoundingBox.h"

#include <allegro5/allegro_primitives.h>

#include "../core/GameState.h"

BoundingBox::BoundingBox(int x, int y, int width, int height)
{
    this->width = width;
    this->height = height;
    update(x, y);
}

void BoundingBox::update(int x, int y)
{
    this->x = x;
    this->y = y;
    this->xMax = x + width;
    this->yMax = y + height;
}

bool BoundingBox::intersects(BoundingBox bbox)
{
    if(x <= bbox.xMax && xMax >= bbox.x &&
            y <= bbox.yMax && yMax >= bbox.y)
        return true;

    return false;
}

void BoundingBox::draw()
{
    al_draw_rectangle(x, y, xMax, yMax, al_map_rgb(255, 0, 0), 1);
}
