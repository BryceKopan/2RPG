#ifndef ACTION_H
#define ACTION_H

#include <ctime>

#include "../gameObject/GameObject.h"

class Action
{
    public:
        GameObject* user;
        std::time_t lastTimeUsed;
        int cooldown;

        Action(GameObject* user, int cooldown);
        
        void useAction();
        virtual void doAction() = 0;
};

#endif
