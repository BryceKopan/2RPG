#include "TileMap.h"

TileMap::TileMap(int tileWidth, int tileHeight)
{
    this->tileWidth = tileWidth;
    this->tileHeight = tileHeight;
    std::unordered_map<int, Tile> tileSet;
}

void TileMap::draw()
{
    for(int y = 0; y < CHUNK_SIZE; y++)
    {
        for(int x = 0; x < CHUNK_SIZE; x++)
        {
            getTile(x, y).draw(x * tileWidth, y * tileHeight);
        }
    }
}

void TileMap::draw(int x, int y)
{
}

Tile TileMap::getTile(int x, int y)
{
    return tileSet[map[x][y]];
}
