#ifndef NPC_H
#define NPC_H

#include "Agent.h"

class NPC : public Agent
{
    public:
        NPC(int x, int y, Sprite sprite);

        void update();
        void doUpdate(){};
    private:
        void npcUpdate();
};

#endif
