#include "GameObject.h"

#include "../../core/GameState.h"

GameObject::GameObject()
{
}

GameObject::GameObject(int x, int y, bool collidable,Sprite sprite)
{
    this->x = x;
    this->y = y;
    this->collidable = collidable;
    this->sprite = sprite;
    hitBox = BoundingBox(x, y, sprite.spriteWidth, sprite.spriteHeight);
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

void GameObject::death()
{
    GameState* gameState = GameState::instance;

    gameState->deadObjects.push_back(this);

    onDeath();
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

std::vector<GameObject*> GameObject::getCollidedObjects(
        std::vector<GameObject*> gameObjects, BoundingBox hitBox)
{
    std::vector<GameObject*> collidedObjects;

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

bool GameObject::collidedWithTiles(BoundingBox hitBox)
{
    TileMap* tileMap = &GameState::instance->tileMap;

    int leftTile = hitBox.x / tileMap->tileWidth;
    int rightTile = hitBox.xMax / tileMap->tileWidth;
    int topTile = hitBox.y / tileMap->tileHeight;
    int bottomTile = hitBox.yMax / tileMap->tileHeight;

    bool collided = false;
    for(int x = leftTile; x <= rightTile; x++)
    {
        for(int y = topTile; y <= bottomTile; y++)
        {
            Tile tile = tileMap->getTile(x, y);

            if(tile.collidable)
            {
                collided = true;
            }
        }
    }

    return collided;
}
