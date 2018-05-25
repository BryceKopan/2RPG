#ifndef ATTACK_H
#define ATTACK_H

#include "../gameObject/GameObject.h"

class Attack : public GameObject
{
    public:
        double lifeTime, creationTime;
        int damage;
        bool playerFriendly;

        Attack(double x, double y, Sprite sprite, bool playerFriendly, 
                double lifeTime, int damage);

        virtual void update();

        virtual void onObjectCollision(ObjectVector gameObjects);
};

#endif
