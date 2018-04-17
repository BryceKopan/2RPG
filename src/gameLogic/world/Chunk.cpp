#include "Chunk.h"

Chunk::Chunk(int x, int y, int tileWidth, int tileHeight)
{
    this->tileMap = TileMap(tileWidth, tileHeight);
    this->x = x;
    this->y = y;
}
