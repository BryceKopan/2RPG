#include "Ability.h"

#include "../../util/Util.h"

Ability::Ability(GameObject* user, double cooldown)
{
    this->user = user;
    this->cooldown = cooldown;
    timeLastUsed = 0;
}

void Ability::useAbility(Point mousePoint)
{
    double currentTime = Util::getPreciseSecondTime();

    if(currentTime - timeLastUsed > cooldown)
    {
        timeLastUsed = currentTime;

        doAbility(mousePoint);
    }
}

int Ability::getAngle(Point location1, Point location2)
{
    int tanY = (location2.y - location1.y);
    int tanX = (location2.x - location1.x);
    int angle = atan2(tanY, tanX) * (180/M_PI);

    if(angle < 0)
        angle = 360 + angle;

    return angle;
}
