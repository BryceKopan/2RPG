#ifndef PLAYER_H
#define PLAYER_H

#include "Agent.h"

class Player : public Agent
{
    public:
        int facingAngle;

        Player(Point location, Sprite sprite);
};

#endif
