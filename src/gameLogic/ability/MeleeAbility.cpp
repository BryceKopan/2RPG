#include "MeleeAbility.h"

#include "../gameObject/attack/MeleeAttack.h"
#include "../GameState.h"

MeleeAbility::MeleeAbility(GameObject* user, double cooldown, 
        Sprite sprite, bool playerFriendly, double lifetime,
        int damage) : 
    AttackAbility(user, cooldown, sprite, playerFriendly, lifetime, 
            damage)
{
}

Location MeleeAbility::getAttackLocation(double mouseX, double mouseY)
{
    //TODO calculate actual position
    return std::make_tuple(mouseX, mouseY);
}

void MeleeAbility::createAttack(Location loc)
{
    GameState* gameState = GameState::instance;

    double x = std::get<0>(loc);
    double y = std::get<1>(loc);
    MeleeAttack* attack = new MeleeAttack(x, y, attackSprite, 
            playerFriendly, lifetime, damage, user);
    gameState->aliveObjects.push_back(attack);
}
