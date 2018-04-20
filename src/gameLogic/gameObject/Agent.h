#ifndef AGENT_H
#define AGENT_H

#include "GameObject.h"

#include <vector>

class Agent : public GameObject
{
    public:
        int dX = 0, dY = 0;

        Agent(int x, int y, Sprite sprite);

        virtual void update();
        virtual void doUpdate(){};

    private:
        std::vector<GameObject*> getCollisions(BoundingBox hitBox);
        bool collidedWithWall(BoundingBox hitBox);
};

#endif
