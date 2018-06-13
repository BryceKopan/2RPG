#ifndef STALK_H
#define STALK_H

#include "../../../gameLogic/ability/Ability.h"

class Stalk : public Ability
{
    public:
        Stalk(GameObject* user, double cooldown, double speedMulti) :
            Ability(user, cooldown), speedMulti(speedMulti){}

        virtual void doAbility(Point mousePoint)
        {
            if(Agent* agent = dynamic_cast<Agent*>(user))
        }

    private:
        double speedMulti;
};

#endif
