#include "Agent.h"

#include <cmath>

#include "../../core/GameState.h"

Agent::Agent(int x, int y, bool collidable, Sprite sprite) : 
    GameObject(x, y, collidable, sprite)
{
}

//TODO move agent up to where the collision is
void Agent::update()
{
    doUpdate();

    move(dX, dY);
}

void Agent::move(int dX, int dY)
{
    GameState* gameState = GameState::instance;

    int oldX = x;
    x += dX;
    hitBox.update(x, y);

    std::vector<GameObject*> collidedObjects = 
        getCollidedObjects(gameState->aliveObjects, hitBox);

    bool collided = (collidedWithTiles(hitBox) || 
            collidedObjects.size() != 0);

    if(collided)
    {
        x = oldX;
    }

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
