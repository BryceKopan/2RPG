#include "Agent.h"

#include <cmath>

#include "../physics/CollisionDetector.h"
#include "../../core/GameState.h"

Agent::Agent(double x, double y, bool collidable, Sprite sprite) : 
    GameObject(x, y, collidable, sprite)
{
}

void Agent::update()
{
    move(dX, dY);

    GameObject::update();
}

void Agent::onObjectCollision(ObjectVector gameObjects)
{
    if(CollisionDetector::detectObjectCollision(this, gameObjects))
    {
        move(-dX, -dY);

        int dx, dy;
        dX != 0 ? dX > 0 ? dx = 1 : dx = -1 : dx = 0;
        dY != 0 ? dY > 0 ? dy = 1 : dy = -1 : dy = 0;

        for(int i = 0; i < dX * dx; i++)
        {
            move(dx, 0);

            if(CollisionDetector::detectObjectCollision(this, gameObjects))
            {
                move(-dx, 0);
                i = dX * dx;
            }
        }

        for(int i = 0; i < dY * dy; i++)
        {
            move(0, dy);

            if(CollisionDetector::detectObjectCollision(this, gameObjects))
            {
                move(0, -dy);
                i = dY * dy;
            }
        }
    }
}

void Agent::onTileCollision()
{
    move(-dX, -dY);

    int dx, dy;
    dX != 0 ? dX > 0 ? dx = 1 : dx = -1 : dx = 0;
    dY != 0 ? dY > 0 ? dy = 1 : dy = -1 : dy = 0;

    for(int i = 0; i < dX * dx; i++)
    {
        move(dx, 0);

        if(CollisionDetector::detectTileCollision(this))
        {
            move(-dx, 0);
            i = dX * dx;
        }
    }

    for(int i = 0; i < dY * dy; i++)
    {
        move(0, dy);

        if(CollisionDetector::detectTileCollision(this))
        {
            move(0, -dy);
            i = dY * dy;
        }
    }
}

void Agent::move(double dX, double dY)
{
    x += dX;
    y += dY;
}
