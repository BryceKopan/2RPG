#ifndef ACTION_H
#define ACTION_H

#include <ctime>

#include "../gameObject/GameObject.h"

class Action
{
    public:
        GameObject* user;
        double cooldown, timeLastUsed;

        Action(GameObject* user, double cooldown);
        
        void useAction(int angle);
        virtual void doAction(int angle) = 0;
};

#endif
