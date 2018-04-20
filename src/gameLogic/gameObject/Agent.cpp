#include "Agent.h"

#include "../../core/GameState.h"

Agent::Agent(int x, int y, Sprite sprite) : 
    GameObject(x, y, sprite)
{
}

//TODO move agent up to where the collision is
void Agent::update()
{
    doUpdate();

    BoundingBox nextHitBox = hitBox.at(x + dX, y + dY);

    std::vector<GameObject*> collidedObjects = 
        getCollisions(nextHitBox);

    if(collidedObjects.size() == 0 && !collidedWithWall(nextHitBox))
    {
        x += dX;
        y += dY;
    }
}

std::vector<GameObject*> Agent::getCollisions(BoundingBox hitBox)
{
    GameState* gameState = GameState::instance;
    std::vector<GameObject*> collidedObjects;

    for(int i = 0; i < gameState->aliveObjects.size(); i++)
    {
        if(hitBox.intersects(gameState->aliveObjects[i]->getHitBox()) &&
                this != gameState->aliveObjects[i])
        {
            collidedObjects.push_back(gameState->aliveObjects[i]);
        }
    }

    return collidedObjects;
}

bool Agent::collidedWithWall(BoundingBox hitBox)
{
    GameState* gameState = GameState::instance;
    TileMap* tileMap = &gameState->tileMap;

    int leftTile = hitBox.x / tileMap->tileWidth;
    int rightTile = hitBox.xMax / tileMap->tileWidth;
    int topTile = hitBox.y / tileMap->tileHeight;
    int bottomTile = hitBox.yMax / tileMap->tileHeight;

    bool collision = false;

    for(int x = leftTile; x <= rightTile; x++)
    {
        for(int y = topTile; y <= bottomTile; y++)
        {
            Tile tile = tileMap->getTile(x, y);

            if(tile.collidable)
            {
                collision = true;
            }
        }
    }

    return collision;
}
