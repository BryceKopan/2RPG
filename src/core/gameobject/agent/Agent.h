#ifndef AGENT_H
#define AGENT_H

#include "../GameObject.h"

class Equipment;

class Agent : public GameObject
{
    public:
        Agent(int x, int y);

        virtual void onDeath(){};
};

#endif
