#include "GameObject.h"

#include "../../core/GameState.h"

GameObject::GameObject(double x, double y, bool collidable,
        Sprite sprite)
{
    this->x = x;
    this->y = y;
    this->collidable = collidable;
    this->sprite = sprite;
    hitBox = BoundingBox(x, y, sprite.spriteWidth, 
            sprite.spriteHeight);

    double hWdith = sprite.spriteWidth/2;
    double hHeight = sprite.spriteHeight/2;

    std::vector<Point> pts;
    pts.push_back(Point(-hWdith, hHeight));
    pts.push_back(Point(hWdith, hHeight));
    pts.push_back(Point(hWdith, -hHeight));
    pts.push_back(Point(-hWdith, -hHeight));
    Point center(x + hWdith, y + hHeight);
    hitPoly = Polygon(center, pts);
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
    sprite.draw(x, y);

    if(GameState::instance->drawHitBoxes)
    {
        //getHitBox().draw();
        getHitPoly().draw();
    }
}

BoundingBox GameObject::getHitBox()
{
    hitBox.update(x, y);
    return hitBox;
}

Polygon GameObject::getHitPoly()
{
    hitPoly.center.x = x + sprite.spriteWidth/2;
    hitPoly.center.y = y + sprite.spriteHeight/2;
    return hitPoly;
}
