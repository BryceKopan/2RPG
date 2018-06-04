#include "TileMap.h"

TileMap::TileMap(int tileWidth, int tileHeight)
{
    this->tileWidth = tileWidth;
    this->tileHeight = tileHeight;
    std::unordered_map<int, Tile> tileSet;

    double hWidth = tileWidth / 2;
    double hHeight = tileHeight / 2;

    std::vector<Point> vertices;
    vertices.push_back(Point(-hWidth, hHeight));
    vertices.push_back(Point(hWidth, hHeight));
    vertices.push_back(Point(hWidth, -hHeight));
    vertices.push_back(Point(-hWidth, -hHeight));
    tileHitPoly = Polygon(vertices);
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

//TODO add draw single tile
void TileMap::draw(int x, int y)
{
}

Tile TileMap::getTile(int x, int y)
{
    return tileSet[map[x][y]];
}

Polygon TileMap::getTileHitPoly(double x, double y)
{
    tileHitPoly.center.x = x;
    tileHitPoly.center.y = y;
    return tileHitPoly;
}
