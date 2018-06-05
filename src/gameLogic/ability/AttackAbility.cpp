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

void AttackAbility::doAbility(double mouseX, double mouseY)
{
    std::tuple<double, double> loc = getAttackLocation(mouseX, mouseY);
    createAttack(loc);
    Ability::useAbility(mouseX, mouseY);
}
