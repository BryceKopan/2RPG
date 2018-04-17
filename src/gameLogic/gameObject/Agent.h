#ifndef AGENT_H
#define AGENT_H

#include "GameObject.h"

class Agent : public GameObject
{
    public:
        int dX = 0, dY = 0;

        Agent(int x, int y, Sprite sprite);

        void update();
        virtual void doUpdate(){};
};

#endif
