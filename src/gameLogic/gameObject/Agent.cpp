#include "Agent.h"

#include <cmath>

#include "../physics/CollisionDetector.h"
#include "../GameState.h"
#include "../../util/Util.h"

Agent::Agent(Point location, double speed, bool collidable, 
        Sprite sprite, int health) : 
    GameObject(location, collidable, sprite)
{
    this->speed = speed;
    this->health = health; 
    this->maxHealth = health;
}

void Agent::update()
{
    for(StatusEffect* effect : statusEffects)
    {
        effect->update();
    }

    move(getAdjustedVelocity(velocity));
}

void Agent::onObjectCollision(ObjectVector gameObjects)
{
    GameState* gameState = GameState::instance;

    if(CollisionDetector::detectObjectCollision(this, gameObjects))
    {
        move(getAdjustedVelocity(-velocity));

        Vector2 unit = velocity.getUnitVector();
        double dX = unit.x * speed * gameState->deltaTime;
        double dY = unit.y * speed * gameState->deltaTime;

        int dx, dy;
        dX != 0 ? dX > 0 ? dx = 1 : dx = -1 : dx = 0;
        dY != 0 ? dY > 0 ? dy = 1 : dy = -1 : dy = 0;

        for(int i = 0; i < dX * dx; i++)
        {
            moveDirect(Vector2(dx, 0));

            if(CollisionDetector::detectObjectCollision(this, gameObjects))
            {
                moveDirect(Vector2(-dx, 0));
                i = dX * dx;
            }
        }

        for(int i = 0; i < dY * dy; i++)
        {
            moveDirect(Vector2(0, dy));

            if(CollisionDetector::detectObjectCollision(this, gameObjects))
            {
                moveDirect(Vector2(0, -dy));
                i = dY * dy;
            }
        }
    }
}

void Agent::onTileCollision()
{
    GameState* gameState = GameState::instance;

    move(getAdjustedVelocity(-velocity));

    Vector2 unit = velocity.getUnitVector();
    double dX = unit.x * speed * gameState->deltaTime;
    double dY = unit.y * speed * gameState->deltaTime;
    
    int dx, dy;
    dX != 0 ? dX > 0 ? dx = 1 : dx = -1 : dx = 0;
    dY != 0 ? dY > 0 ? dy = 1 : dy = -1 : dy = 0;

    for(int i = 0; i < dX * dx; i++)
    {
        moveDirect(Vector2(dx, 0));

        if(CollisionDetector::detectTileCollision(this))
        {
            moveDirect(Vector2(-dx, 0));
            i = dX * dx;
        }
    }

    for(int i = 0; i < dY * dy; i++)
    {
        moveDirect(Vector2(0, dy));

        if(CollisionDetector::detectTileCollision(this))
        {
            moveDirect(Vector2(0, -dy));
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
    if(dHealth < 0)
        timeLastDamaged = Util::getPreciseSecondTime();
    if(health > maxHealth)
        health = maxHealth;
    else if(health <= 0)
        kill();
}

void Agent::useAbility(int i, Point mousePoint)
{
    abilities[i]->useAbility(mousePoint);
    timeLastActed = Util::getPreciseSecondTime();
}

void Agent::moveDirect(Vector2 vector)
{
    location += vector;
}

void Agent::move(Vector2 vector)
{
    location += vector;
}
    
Vector2 Agent::getAdjustedVelocity(Vector2 velocity)
{
    GameState* gameState = GameState::instance;
    Vector2 adjustedVelocity;

    Vector2 unit = velocity.getUnitVector();

    adjustedVelocity.x = unit.x * speed * gameState->deltaTime;
    adjustedVelocity.y = unit.y * speed * gameState->deltaTime;

    return adjustedVelocity;
}
