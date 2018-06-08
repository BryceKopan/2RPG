#ifndef PLAYER_H
#define PLAYER_H

#include "Agent.h"
#include "../ability/Ability.h"

class Player : public Agent
{
    public:
        int facingAngle;
        Ability* abilities[4];

        Player(double x, double y, Sprite sprite);
};

#endif
