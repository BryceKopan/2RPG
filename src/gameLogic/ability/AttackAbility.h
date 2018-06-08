#ifndef ATTACK_ABILITY_H
#define ATTACK_ABILITY_H

#include "Ability.h"

#include "../../graphics/Sprite.h"

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

        virtual void doAbility(Point mousePoint);
    private:
        virtual Point getAttackLocation(Point mousePoint) = 0;

        virtual void createAttack(Point attackPoint) = 0;
}; 

#endif
