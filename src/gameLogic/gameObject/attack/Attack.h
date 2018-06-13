#ifndef ATTACK_H
#define ATTACK_H

#include "../GameObject.h"

class Attack : public GameObject
{
    public:
        double lifetime, creationTime;
        int damage;
        bool playerFriendly;

        Attack(Point location, Sprite sprite, bool playerFriendly, 
                double lifetime, int damage);

        virtual void update();

        virtual void onObjectCollision(ObjectVector gameObjects);
};

#endif
