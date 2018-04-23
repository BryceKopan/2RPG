#include "Agent.h"

#include <cmath>

#include "../../core/GameState.h"

Agent::Agent(int x, int y, bool collidable, Sprite sprite) : 
    GameObject(x, y, collidable, sprite)
{
}

void Agent::update()
{
    doUpdate();

    move(dX, dY);
}

//TODO move agent up to where the collision is
void Agent::move(int dX, int dY)
{
    GameState* gameState = GameState::instance;
    std::vector<GameObject*> collidedObjects;
    bool collided;

    if(dX != 0)
    {
        int oldX = x;
        x += dX;
        hitBox.update(x, y);

        collidedObjects = 
            getCollidedObjects(gameState->aliveObjects, hitBox);

        collided = (collidedWithTiles(hitBox) || 
                collidedObjects.size() != 0);

        if(collided)
        {
            x = oldX;
        }
    }

    if(dY != 0)
    {
        int oldY = y;
        y += dY;
        hitBox.update(x, y);

        collidedObjects = 
            getCollidedObjects(gameState->aliveObjects, hitBox);

        collided = (collidedWithTiles(hitBox) || 
                collidedObjects.size() != 0);

        if(collided)
        {
            y = oldY;
        }
    }
}
