#ifndef STALK_H
#define STALK_H

#include "../../../gameLogic/ability/Ability.h"

#include "../../../gameLogic/ability/effects/Invisible.h"

class Stalk : public Ability
{
    public:
        Stalk(GameObject* user, double cooldown, double speedMulti) :
            Ability(user, cooldown), speedMulti(speedMulti){}

        virtual void doAbility(Point mousePoint)
        {
            if(Agent* agent = dynamic_cast<Agent*>(user))
            {
                StatusEffect* effect = new Invisible(agent, 2);
                effect->start();
            }
        }

    private:
        double speedMulti;
};

#endif
