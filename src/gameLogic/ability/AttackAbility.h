#ifndef ATTACK_ABILITY_H
#define ATTACK_ABILITY_H

#include "Ability.h"

#include <tuple>
#include "../../graphics/Sprite.h"

typedef std::tuple<double, double> Location;

class AttackAbility : public Ability
{
    public:
        Sprite attackSprite;
        bool playerFriendly;
        double lifetime;
        int damage;

        AttackAbility(GameObject* user, double cooldown, 
                Sprite sprite, bool playerFriendly, double lifetime,
                int damage);

        virtual void doAbility(double mouseX, double mouseY);
    private:
        virtual Location getAttackLocation(double x, double y) = 0;

        virtual void createAttack(Location) = 0;
}; 

#endif
