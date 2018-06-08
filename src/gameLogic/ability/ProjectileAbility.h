#ifndef PROJECTILE_ABILITY_H
#define PROJECTILE_ABILITY_H

#include "AttackAbility.h"

#include"../../util/Vector2.h"

class ProjectileAbility : public AttackAbility
{
    public:
        ProjectileAbility(GameObject* user, double cooldown, 
                Sprite sprite, bool playerFriendly, double lifetime, 
                int damage, double speed);
    private:
        Vector2 velocity;
        double speed;

        virtual Point getAttackLocation(Point mousePoint);
        virtual void createAttack(Point attackPoint);
};

#endif
