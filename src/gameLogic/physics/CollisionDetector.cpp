#include "CollisionDetector.h"

#include "SATCollision.h"
#include "../GameState.h"

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

    const Polygon* hitPoly = object->getHitPoly();
    Vector2 xAxis = Vector2(1, 0);
    Vector2 yAxis = Vector2(0 ,1);
    Projection pX = SATCollision::getProjection(hitPoly, xAxis);
    Projection pY = SATCollision::getProjection(hitPoly, yAxis);

    TileMap* tileMap = &gameState->tileMap;
    int tileWidth = tileMap->tileWidth;
    int tileHeight = tileMap->tileHeight;

    int leftTile = std::get<0>(pX) / tileWidth;
    int rightTile = std::get<1>(pX) / tileWidth;
    int topTile = std::get<0>(pY) / tileHeight;
    int bottomTile = std::get<1>(pY) / tileHeight;

    for(int x = leftTile; x <= rightTile; x++)
    {
        for(int y = topTile; y <= bottomTile; y++)
        {
            Tile tile = tileMap->getTile(x, y);

            if(tile.collidable)
            {
                double tX = x * tileWidth + tileWidth / 2;
                double tY = y * tileHeight + tileHeight / 2;
                const Polygon* tilePoly = tileMap->getHitPoly(tX, tY);

                if(SATCollision::intersect(hitPoly, tilePoly))
                    return true;
            }
        }
    }

    return false;
}

ObjectVector CollisionDetector::getCollidedObjects(GameObject* object,
        ObjectVector gameObjects)
{
    const Polygon* currentHitPoly = object->getHitPoly();
    ObjectVector collidedObjects;

    for(int i = 0; i < gameObjects.size(); i++)
    {
        const Polygon* objectHitPoly = gameObjects[i]->getHitPoly();

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

