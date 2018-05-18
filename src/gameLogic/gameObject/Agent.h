#ifndef AGENT_H
#define AGENT_H

#include "GameObject.h"

class Agent : public GameObject
{
    public:
        double dX = 0, dY = 0;

        Agent(double x, double y, bool collidable, Sprite sprite);

        virtual void update();
        virtual void onObjectCollision(ObjectVector gameObjects);
        virtual void onTileCollision();

    private:
        void move(double dX, double dY);
        void correctPosition();
};

#endif
