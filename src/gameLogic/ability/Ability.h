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
        
        virtual void useAbility(double mouseX, double mouseY);
        virtual void doAbility(double mouseX, double mouseY){};
};

#endif
