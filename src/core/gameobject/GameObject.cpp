#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::GameObject(int x, int y, Sprite sprite)
{
    this->x = x;
    this->y = y;
    this->sprite = sprite;
}

void GameObject::draw()
{
    sprite.draw(x, y);
}

BoundingBox GameObject::getHitBox()
{
    return BoundingBox(x, y, sprite.spriteWidth, sprite.spriteHeight);
}
