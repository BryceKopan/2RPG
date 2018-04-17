#include "Agent.h"

Agent::Agent(int x, int y, Sprite sprite) : 
    GameObject(x, y, sprite)
{
}

//Make sure to update NPC update method to match update
void Agent::update()
{
    doUpdate();

    x += dX;
    y += dY;
}
