#include "TileMap.h"

TileMap::TileMap(int mapWidth, int mapHeight, 
        int tileWidth, int tileHeight)
{
    this->mapWidth = mapWidth;
    this->mapHeight = mapHeight;
    this->tileWidth = tileWidth;
    this->tileHeight = tileHeight;
    std::unordered_map<int, Tile> tileSet;

    map = std::vector<std::vector<int>>(mapHeight, 
            std::vector<int>(mapWidth, 0));

    double hWidth = tileWidth / 2;
    double hHeight = tileHeight / 2;

    std::vector<Point> vertices;
    vertices.push_back(Point(-hWidth, hHeight));
    vertices.push_back(Point(hWidth, hHeight));
    vertices.push_back(Point(hWidth, -hHeight));
    vertices.push_back(Point(-hWidth, -hHeight));
    hitPoly = Polygon(vertices);
}

void TileMap::draw()
{
    for(int y = 0; y < mapHeight; y++)
    {
        for(int x = 0; x < mapWidth; x++)
        {
            getTile(x, y).draw(Point(x * tileWidth + tileWidth / 2, 
                        y * tileHeight + tileHeight / 2));
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

Polygon* TileMap::getHitPoly(Point location)
{
    hitPoly.center = location;
    return &hitPoly;
}
