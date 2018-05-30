#ifndef MELEE_ABILITY_H
#define MELEE_ABILITY_H

#include "AttackAbility.h"

class MeleeAbility : public AttackAbility
{
    public:
        MeleeAbility(GameObject* user, double cooldown, Sprite sprite,
                bool playerFriendly, double lifetime, int damage);
    private:
        virtual Location getAttackLocation(double mouseX, double mouseY);
        virtual void createAttack(Location loc);
};

#endif
