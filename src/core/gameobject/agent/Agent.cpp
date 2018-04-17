#include "Agent.h"

Agent::Agent(int x, int y, Sprite sprite) : 
    GameObject(x, y, sprite)
{
}

void Agent::update()
{
    x += dX;
    y += dY;

    doUpdate();
}
