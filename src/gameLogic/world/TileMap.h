#ifndef TILE_MAP_H
#define TILE_MAP_H

#include <vector>
#include <unordered_map>

#include "Tile.h"
#include "../../util/Polygon.h"

class TileMap
{
    public:
        int mapWidth, mapHeight, tileWidth, tileHeight;
        std::unordered_map<int , Tile> tileSet;
        std::vector< std::vector<int> > map = {};      

        TileMap(){};
        TileMap(int mapWidth, int mapHeight, 
                int tileWidth, int tileHeight);

        void draw();
        void draw(int x, int y);
        Tile getTile(int x, int y);
        Polygon* getHitPoly(Point location);
    private:
        Polygon hitPoly;
};

#endif
