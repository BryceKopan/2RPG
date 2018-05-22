#include "Action.h"

#include "../../util/Util.h"

Action::Action(GameObject* user, double cooldown)
{
    this->user = user;
    this->cooldown = cooldown;
    timeLastUsed = 0;
}

void Action::useAction(int angle)
{
    double currentTime = Util::getPreciseSecondTime();

    if(currentTime - timeLastUsed > cooldown)
    {
        timeLastUsed = currentTime;

        doAction(angle);
    }
}
