#ifndef NPC_H
#define NPC_H

#include "Agent.h"

class NPC : public Agent
{
    public:
        int detectionRange = 0;

        NPC(int x, int y, Sprite sprite, int detectionRange);

        void update();
        void doUpdate(){};
    private:
        void npcUpdate();
        void setMovement();
};

#endif
