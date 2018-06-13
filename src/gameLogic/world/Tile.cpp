#include "Tile.h"

Tile::Tile(bool collidable, Sprite sprite)
{
    this->collidable = collidable;
    this->sprite = sprite;
}

void Tile::draw(Point location)
{
    sprite.draw(location);   
}
