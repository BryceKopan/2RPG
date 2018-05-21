#include "Action.h"

#include "../../util/Util.h"

Action::Action(GameObject* user, int cooldown)
{
    this->user = user;
    this->cooldown = cooldown;
    timeLastUsed = 0;
}

void Action::useAction(int angle)
{
    long currentTime = Util::getMillisecondTime();

    if(currentTime - timeLastUsed > cooldown)
    {
        timeLastUsed = currentTime;

        doAction(angle);
    }
}
