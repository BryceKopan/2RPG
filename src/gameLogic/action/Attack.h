#ifndef ATTACK_H
#define ATTACK_H

#include <ctime>

#include "../gameObject/GameObject.h"

class Attack : public GameObject
{
    public:
        int lifeTime;
        std::time_t creationTime;
        bool playerFriendly;

        Attack(int x, int y, Sprite sprite, bool playerFriendly, int lifeTime);

        virtual void update();
        virtual void doUpdate(){};
};

#endif
