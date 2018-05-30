#ifndef AOE_ABILITY_H
#define AOE_ABILITY_H

#include "AttackAbility.h"

class AOEAbility : public AttackAbility
{
    public:
        AOEAbility(GameObject* user, double cooldown, Sprite sprite,
                bool playerFriendly, double lifetime, int damage);
    private:
        virtual std::tuple<double, double> 
            getAttackLocation(double mouseX, double mouseY);
        virtual void createAttack(std::tuple<double, double> loc);
};

#endif
