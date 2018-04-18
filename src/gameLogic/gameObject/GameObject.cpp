#include "GameObject.h"

#include "../../core/GameState.h"

GameObject::GameObject()
{
}

GameObject::GameObject(int x, int y, Sprite sprite)
{
    this->x = x;
    this->y = y;
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
