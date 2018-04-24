#include "Action.h"

Action::Action(GameObject* user, int cooldown)
{
    this->user = user;
    this->cooldown = cooldown;
    lastTimeUsed = std::time(nullptr);
}

void Action::useAction()
{
    std::time_t currentTime = std::time(nullptr);

    if(currentTime - lastTimeUsed > cooldown)
    {
        lastTimeUsed = currentTime;

        doAction();
    }
}
