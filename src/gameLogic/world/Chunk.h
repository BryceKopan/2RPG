#ifndef CHUNK_H
#define CHUNK_H

#include "TileMap.h"

class Chunk
{
    public:
        TileMap tileMap;
        int x, y;

        Chunk(int x, int y, int tileWidth, int tileHeight);
    private:
};

#endif
