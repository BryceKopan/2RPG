#ifndef PLAYER_H
#define PLAYER_H

#include "../../gameLogic/ability/Ability.h"
#include "../../gameLogic/gameObject/Agent.h"

class Player : public Agent
{
    public:
        int facingAngle;
        Ability* ability;

        Player(double x, double y, Sprite sprite);
};

#endif
