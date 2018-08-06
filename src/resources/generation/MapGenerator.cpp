#include "MapGenerator.h"

#include "../../gameLogic/gameObject/NPC.h"

void MapGenerator::populateMap()
{
    GameState* gameState = GameState::instance;
    TileMap tileMap = gameState->tileMap;

    for(int y = 0; y < tileMap.mapHeight; y++)
    {
        for(int x = 0; x < tileMap.mapWidth; x++)
        {
            if(!tileMap.getTile(x, y).collidable 
                    && rand() % 1000 == 0)
            {
                Sprite sprite = 
                    Sprite("res/dungeon1.png", Point(64, 192), 32, 32);
                Point location = 
                    Point(x * tileMap.tileWidth + 16, 
                            y * tileMap.tileHeight + 16);
                gameState->aliveObjects.push_back(
                        new NPC(location, true, sprite, 100, 100));
            }
        }
    }
}
