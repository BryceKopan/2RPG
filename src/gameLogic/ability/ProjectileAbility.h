#ifndef PROJECTILE_ABILITY_H
#define PROJECTILE_ABILITY_H

#include "AttackAbility.h"

#include"../../util/Vector2.h"

class ProjectileAbility : public AttackAbility
{
    public:
        ProjectileAbility(GameObject* user, double cooldown, 
                Sprite sprite, bool playerFriendly, double lifetime, 
                int damage, Vector2 velocity, double speed);
    private:
        Vector2 velocity;
        double speed;

        virtual std::tuple<double, double> 
            getAttackLocation(double mouseX, double mouseY);
        virtual void createAttack(std::tuple<double, double> loc);
};

#endif
