#ifndef ABILITY_H
#define ABILITY_H

#include <ctime>

#include "../gameObject/GameObject.h"
#include "../../util/Point.h"

class Ability
{
    public:
        GameObject* user;
        double cooldown, timeLastUsed;

        Ability(GameObject* user, double cooldown);
        
        virtual void useAbility(Point mousePoint);
        virtual void doAbility(Point mousePoint){};
    
    protected:
        int getAngle(Point location1, Point location2);
};

#endif
