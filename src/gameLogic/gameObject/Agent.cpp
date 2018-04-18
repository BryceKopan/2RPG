#include "Agent.h"

#include "../../core/GameState.h"

Agent::Agent(int x, int y, Sprite sprite) : 
    GameObject(x, y, sprite)
{
}

//TODO move agent up to where the collision is
void Agent::update()
{
    doUpdate();

    std::vector<GameObject*> collidedObjects = 
        getCollisions(hitBox.at(x + dX, y + dY));

    if(collidedObjects.size() == 0)
    {
        x += dX;
        y += dY;
    }
}

std::vector<GameObject*> Agent::getCollisions(BoundingBox hitBox)
{
    GameState* gameState = GameState::instance;
    std::vector<GameObject*> collidedObjects;

    for(int i = 0; i < gameState->aliveObjects.size(); i++)
    {
        if(hitBox.intersects(gameState->aliveObjects[i]->getHitBox()) &&
                this != gameState->aliveObjects[i])
        {
            collidedObjects.push_back(gameState->aliveObjects[i]);
        }
    }

    return collidedObjects;
}
