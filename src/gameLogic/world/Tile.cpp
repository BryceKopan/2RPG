#include "Tile.h"

Tile::Tile(bool collidable, Sprite sprite)
{
    this->collidable = collidable;
    this->sprite = sprite;
}

void Tile::draw(int x, int y)
{
    sprite.draw(x, y);   
}
