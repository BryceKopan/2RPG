#ifndef PLAYER_H
#define PLAYER_H

#include "Agent.h"
#include "../ability/Ability.h"

class Player : public Agent
{
    public:
        int facingAngle;
        Ability* ability;

        Player(double x, double y, Sprite sprite);
};

#endif
