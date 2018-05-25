#ifndef NPC_H
#define NPC_H

#include "Agent.h"

class NPC : public Agent
{
    public:
        double detectionRange = 0;

        NPC(double x, double y, bool collidable, Sprite sprite, 
                int health, double detectionRange);

        void update();
        void doUpdate(){};
    private:
        void npcUpdate();
        void setMovement();
};

#endif
