#include "GameObject.h"

#include "../../core/GameState.h"

GameObject::GameObject(int x, int y, bool collidable,Sprite sprite)
{
    this->x = x;
    this->y = y;
    this->collidable = collidable;
    this->sprite = sprite;
    hitBox = BoundingBox(x, y, sprite.spriteWidth, sprite.spriteHeight);
}

void GameObject::update()
{
    ObjectVector collidedObjects = getCollidedObjects(getHitBox());

    if(collidedObjects.size() > 0)
        onObjectCollision(collidedObjects);

    TileVector collidedTiles = getCollidedTiles(getHitBox());

    if(collidedTiles.size() > 0)
        onTileCollision(collidedTiles);
}

void GameObject::death()
{
    GameState* gameState = GameState::instance;

    gameState->deadObjects.push_back(this);
}

void GameObject::deathCleanup()
{
    GameState* gameState = GameState::instance;

    for(int i = 0; i < gameState->aliveObjects.size(); i++)
    {
        if(this == gameState->aliveObjects[i])
        {
            gameState->aliveObjects.erase(gameState->aliveObjects.begin() + i);
        }
    }

    delete this;
}

void GameObject::draw()
{
    sprite.draw(x, y);

    if(GameState::instance->drawHitBoxes)
    {
        getHitBox().draw();
    }
}

BoundingBox GameObject::getHitBox()
{
    hitBox.update(x, y);
    return hitBox;
}

ObjectVector GameObject::getCollidedObjects(BoundingBox hitBox)
{
    GameState* gameState = GameState::instance;
    ObjectVector gameObjects = gameState->aliveObjects;
    ObjectVector collidedObjects;

    for(int i = 0; i < gameObjects.size(); i++)
    {
        if(hitBox.intersects(gameObjects[i]->getHitBox()) &&
                this != gameObjects[i])
        {
            collidedObjects.push_back(gameObjects[i]);
        }
    }

    return collidedObjects;
}

TileVector GameObject::getCollidedTiles(BoundingBox hitBox)
{
    GameState* gameState = GameState::instance;
    TileMap* tileMap = &gameState->tileMap;
    TileVector collidedTiles;

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
                collidedTiles.push_back(std::make_tuple(x, y));
            }
        }
    }

    return collidedTiles;
}
