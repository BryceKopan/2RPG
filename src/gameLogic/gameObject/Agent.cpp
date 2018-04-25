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
    move(dX, dY);

    GameObject::update();
}

void Agent::move(int dX, int dY)
{
    GameState* gameState = GameState::instance;

    int oldX = x;
    x += dX;

    ObjectVector collidedObjects = getCollidedObjects(getHitBox());

    TileVector collidedTiles = getCollidedTiles(getHitBox());

    bool collided = 
        (collidedObjects.size() != 0 || collidedTiles.size() != 0);

    if(collided)
    {
        x = oldX;
    }

    int oldY = y;
    y += dY;

    collidedObjects = getCollidedObjects(getHitBox());

    collidedTiles = getCollidedTiles(getHitBox());

    collided = 
        (collidedObjects.size() != 0 || collidedTiles.size() != 0);

    if(collided)
    {
        y = oldY;
    }
}
