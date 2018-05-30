#include "Ability.h"

#include "../../util/Util.h"

Ability::Ability(GameObject* user, double cooldown)
{
    this->user = user;
    this->cooldown = cooldown;
    timeLastUsed = 0;
}

void Ability::useAbility(double mouseX, double mouseY)
{
    double currentTime = Util::getPreciseSecondTime();

    if(currentTime - timeLastUsed > cooldown)
    {
        timeLastUsed = currentTime;

        doAbility(mouseX, mouseY);
    }
}
