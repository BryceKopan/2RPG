#include "NPC.h"

#include <math.h>

#include "../../core/GameState.h"

NPC::NPC(double x, double y, bool collidable, Sprite sprite, 
        double detectionRange) :
    Agent(x, y, collidable, sprite)
{
    this->detectionRange = detectionRange;
}

//Duplicate Agent Update and call npcUpdate
//Done to solve the multi-level hook problem
void NPC::update()
{
    npcUpdate();
    Agent::update();
    doUpdate();
}

void NPC::npcUpdate()
{
    setMovement();
}

void NPC::setMovement()
{
    Agent player = *GameState::instance->player;

    if(sqrt(pow(player.x - x, 2) + pow(player.y - y, 2)) <= 
            detectionRange)
    {
        if(player.x < x && player.y < y)
        {
            dX = -1;
            dY = -1;
        }
        else if(player.x == x && player.y < y)
        {
            dX = 0;
            dY = -1;
        }
        else if(player.x > x && player.y < y)
        {
            dX = 1;
            dY = -1;
        }
        else if(player.x > x && player.y == y)
        {
            dX = 1;
            dY = 0;
        }
        else if(player.x > x && player.y > y)
        {
            dX = 1;
            dY = 1;
        }
        else if(player.x == x && player.y > y)
        {
            dX = 0;
            dY = 1;
        }
        else if(player.x < x && player.y > y)
        {
            dX = -1;
            dY = 1;
        }
        else if(player.x < x && player.y == y)
        {
            dX = -1;
            dY = 0;
        }
    }
    else
    {
        dX = 0;
        dY = 0;
    }
}
