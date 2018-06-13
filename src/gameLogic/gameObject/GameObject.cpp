#include "GameObject.h"

#include "../GameState.h"

GameObject::GameObject(Point location, bool collidable,
        Sprite sprite)
{
    this->location = location;
    this->collidable = collidable;
    this->sprite = sprite;

    double hWidth = sprite.spriteWidth/2;
    double hHeight = sprite.spriteHeight/2;

    std::vector<Point> vertices;
    vertices.push_back(Point(-hWidth, hHeight));
    vertices.push_back(Point(hWidth, hHeight));
    vertices.push_back(Point(hWidth, -hHeight));
    vertices.push_back(Point(-hWidth, -hHeight));
    hitPoly = Polygon(location, vertices);
}

void GameObject::kill()
{
    GameState* gameState = GameState::instance;

    if(isAlive)
    {
        gameState->deadObjects.push_back(this);
        isAlive = false;
    }
}

void GameObject::death()
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
    sprite.draw(location);

    if(GameState::instance->drawHitBoxes)
    {
        getHitPoly()->draw();
    }
}

Polygon* GameObject::getHitPoly()
{
    hitPoly.center = location;
    return &hitPoly;
}
