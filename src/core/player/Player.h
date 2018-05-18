#ifndef PLAYER_H
#define PLAYER_H

#include "../actions/TestAction.h"
#include "../../gameLogic/gameObject/Agent.h"

class Player : public Agent
{
    public:
        int facingAngle;
        Action* action;

        Player(double x, double y, Sprite sprite);
};

#endif
