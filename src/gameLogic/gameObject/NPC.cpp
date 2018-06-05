#include "NPC.h"

#include <math.h>

#include "../GameState.h"

NPC::NPC(double x, double y, bool collidable, Sprite sprite, 
        int health, double detectionRange) :
    Agent(x, y, 90, collidable, sprite, health)
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

    Vector2 vectorToPlayer(player.x - x, player.y - y);

    if(vectorToPlayer.getMagnitude() <= detectionRange)
    {
        velocity = vectorToPlayer;
    }
    else
    {
        velocity = Vector2(0, 0);
    }
}
