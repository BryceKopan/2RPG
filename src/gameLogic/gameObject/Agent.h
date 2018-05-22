#ifndef AGENT_H
#define AGENT_H

#include "GameObject.h"

#include "../../util/Vector2.h"

class Agent : public GameObject
{
    public:
        Vector2 velocity;
        double speed;

        Agent(double x, double y, double speed , bool collidable, 
                Sprite sprite);

        virtual void update();
        virtual void onObjectCollision(ObjectVector gameObjects);
        virtual void onTileCollision();

    private:
        void move(Vector2 vector);
        void move(double dX, double dY);
        void correctPosition();
};

#endif
