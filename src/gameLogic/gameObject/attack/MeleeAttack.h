#ifndef MELEE_ATTACK_H
#define MELEE_ATTACK_H

#include "Attack.h"

class MeleeAttack : public Attack
{
    public:
        MeleeAttack(double x, double y, Sprite sprite, 
                bool playerFriendly, double lifetime, int damage, 
                GameObject* user);

        virtual void update();
    private:
        GameObject* user;
        double xOffSet, yOffSet;
};

#endif
