#ifndef ATTACK_H
#define ATTACK_H

#include "../gameObject/GameObject.h"

class Attack : public GameObject
{
    public:
        int lifeTime;
        long creationTime;
        bool playerFriendly;

        Attack(int x, int y, Sprite sprite, bool playerFriendly, int lifeTime);

        virtual void update();

        virtual void onObjectCollision(ObjectVector gameObjects);
};

#endif
