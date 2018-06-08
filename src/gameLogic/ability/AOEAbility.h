#ifndef AOE_ABILITY_H
#define AOE_ABILITY_H

#include "AttackAbility.h"

class AOEAbility : public AttackAbility
{
    public:
        AOEAbility(GameObject* user, double cooldown, Sprite sprite,
                bool playerFriendly, double lifetime, int damage);
    private:
        virtual Point getAttackLocation(Point mousePoint);
        virtual void createAttack(Point attackPoint);
};

#endif
