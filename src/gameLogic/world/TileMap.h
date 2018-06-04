#ifndef TILE_MAP_H
#define TILE_MAP_H

#include <unordered_map>

#include "../CONSTANTS.h"
#include "Tile.h"
#include "../../util/Polygon.h"

class TileMap
{
    public:
        int tileWidth, tileHeight;
        std::unordered_map<int , Tile> tileSet;
        int map[CHUNK_SIZE][CHUNK_SIZE] = {};      

        TileMap(){};
        TileMap(int tileWidth, int tileHeight);

        void draw();
        void draw(int x, int y);
        Tile getTile(int x, int y);
        Polygon getTileHitPoly(double x, double y);
    private:
        Polygon tileHitPoly;
};

#endif
