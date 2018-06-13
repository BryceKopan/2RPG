#ifndef NPC_H
#define NPC_H

#include "Agent.h"

class NPC : public Agent
{
    public:
        double detectionRange = 0;

        NPC(Point location, bool collidable, Sprite sprite, 
                int health, double detectionRange);

        void update();
        void doUpdate(){};
    private:
        void npcUpdate();
        void setMovement();
};

#endif
