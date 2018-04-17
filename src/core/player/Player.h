#ifndef PLAYER_H
#define PLAYER_H

#include "../../gameLogic/gameObject/Agent.h"

class Player : public Agent
{
    public:
        Player(int x, int y, Sprite sprite);
};

#endif
