#ifndef PLAYER_H
#define PLAYER_H

#include "../actions/TestAction.h"
#include "../../gameLogic/gameObject/Agent.h"

class Player : public Agent
{
    public:
        int facingAngle;
        Action* action;

        Player(int x, int y, Sprite sprite);
};

#endif
