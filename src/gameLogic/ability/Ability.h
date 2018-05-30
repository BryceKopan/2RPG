#ifndef ABILITY_H
#define ABILITY_H

#include <ctime>

#include "../gameObject/GameObject.h"

class Ability
{
    public:
        GameObject* user;
        double cooldown, timeLastUsed;

        Ability(GameObject* user, double cooldown);
        
        void useAbility(int angle);
        virtual void doAbility(int angle) = 0;
};

#endif
