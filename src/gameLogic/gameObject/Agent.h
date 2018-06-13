#ifndef AGENT_H
#define AGENT_H

#include "GameObject.h"

#include "../../util/Vector2.h"

class Agent : public GameObject
{
    public:
        Vector2 velocity;
        double speed, maxHealth;

        Agent(Point location, double speed , bool collidable, 
                Sprite spritei, int health);

        virtual void update();
        virtual void onObjectCollision(ObjectVector gameObjects);
        virtual void onTileCollision();

        int getHealth();
        void changeHealth(int dHealth);
    private:
        int health;

        void move(Vector2 vector);
        void move(double dX, double dY);
        void correctPosition();
};

#endif
