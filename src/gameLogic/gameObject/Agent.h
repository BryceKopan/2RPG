#ifndef AGENT_H
#define AGENT_H

#include "GameObject.h"

class Agent : public GameObject
{
    public:
        int dX = 0, dY = 0;

        Agent(int x, int y, bool collidable, Sprite sprite);

        virtual void update();
        virtual void onObjectCollision(ObjectVector gameObjects);
        virtual void onTileCollision();

    private:
        void move(int dX, int dY);
        void correctPosition();
};

#endif
