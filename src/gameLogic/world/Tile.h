#ifndef TILE_H
#define TILE_H

#include <string>

#include "../../graphics/Sprite.h"

class Tile
{
    public:
        Sprite sprite;
        bool collidable;

        Tile(){};
        Tile(bool collidable, Sprite sprite);
    private:
};

#endif
