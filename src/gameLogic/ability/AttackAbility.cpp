#include "AttackAbility.h"

AttackAbility::AttackAbility(GameObject* user, double cooldown, 
        Sprite sprite, bool playerFriendly, double lifetime, 
        int damage) : Ability(user, cooldown)
{
    this->attackSprite = sprite;
    this->playerFriendly = playerFriendly;
    this->lifetime = lifetime;
    this->damage = damage;
}

void AttackAbility::doAbility(Point mousePoint)
{
    Point attackPoint = getAttackLocation(mousePoint);
    createAttack(attackPoint);
    Ability::useAbility(mousePoint);
}
