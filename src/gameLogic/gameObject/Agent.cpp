#include "Agent.h"

#include <cmath>

#include "../physics/CollisionDetector.h"
#include "../../core/GameState.h"

Agent::Agent(double x, double y, double speed, bool collidable, 
        Sprite sprite, int health) : 
    GameObject(x, y, collidable, sprite)
{
    this->speed = speed;
    this->health = health; 
    this->maxHealth = health;
}

void Agent::update()
{
    move(velocity);
}

void Agent::onObjectCollision(ObjectVector gameObjects)
{
    GameState* gameState = GameState::instance;

    if(CollisionDetector::detectObjectCollision(this, gameObjects))
    {
        move(-velocity);

        double dX = velocity.getNormalX() * speed * gameState->deltaTime;
        double dY = velocity.getNormalY() * speed * gameState->deltaTime;

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
    GameState* gameState = GameState::instance;

    move(-velocity);

    double dX = velocity.getNormalX() * speed * gameState->deltaTime;
    double dY = velocity.getNormalY() * speed * gameState->deltaTime;
    
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

int Agent::getHealth()
{
    return health;
}

void Agent::changeHealth(int dHealth)
{
    health += dHealth;
    if(health > maxHealth)
        health = maxHealth;
    else if(health <= 0)
        kill();
}

void Agent::move(Vector2 vector)
{
    GameState* gameState = GameState::instance;

    vector.normalize();

    x += vector.x * speed * gameState->deltaTime;
    y += vector.y * speed * gameState->deltaTime;
}

void Agent::move(double dX, double dY)
{
    x += dX;
    y += dY;
}
