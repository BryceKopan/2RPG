#include "CollisionDetector.h"

#include "SATCollision.h"
#include "../../core/GameState.h"

void CollisionDetector::resolveCollisions(GameObject* object)
{
    GameState* gameState = GameState::instance;

    if(detectTileCollision(object))
        object->onTileCollision();

    ObjectVector collidedObjects;
    collidedObjects = getCollidedObjects(object, gameState->aliveObjects);

    if(collidedObjects.size() > 0)
        object->onObjectCollision(collidedObjects);
}

bool CollisionDetector::detectObjectCollision(GameObject* object, 
        ObjectVector gameObjects)
{
    ObjectVector collidedObjects;
    collidedObjects = getCollidedObjects(object, gameObjects);

    for(int i = 0; i < collidedObjects.size(); i++)
    {
        if(gameObjects[i]->collidable)
            return true;
    }

    return false;
}

bool CollisionDetector::detectTileCollision(GameObject* object)
{
    GameState* gameState = GameState::instance;
    TileMap* tileMap = &gameState->tileMap;
    BoundingBox hitBox = object->getHitBox();

    int leftTile = hitBox.x / tileMap->tileWidth;
    int rightTile = hitBox.xMax / tileMap->tileWidth;
    int topTile = hitBox.y / tileMap->tileHeight;
    int bottomTile = hitBox.yMax / tileMap->tileHeight;

    for(int x = leftTile; x <= rightTile; x++)
    {
        for(int y = topTile; y <= bottomTile; y++)
        {
            Tile tile = tileMap->getTile(x, y);

            if(tile.collidable)
            {
                return true;
            }
        }
    }

    return false;
}

ObjectVector CollisionDetector::getCollidedObjects(GameObject* object,
        ObjectVector gameObjects)
{
    Polygon currentHitPoly = object->getHitPoly();
    ObjectVector collidedObjects;

    for(int i = 0; i < gameObjects.size(); i++)
    {
        Polygon objectHitPoly = gameObjects[i]->getHitPoly();

        if(object != gameObjects[i])
        {
            if(SATCollision::intersect(currentHitPoly, objectHitPoly))
            {
                collidedObjects.push_back(gameObjects[i]);
            }
        }
    }

    return collidedObjects;
}

