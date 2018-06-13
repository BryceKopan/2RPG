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

Point MeleeAbility::getAttackLocation(Point mousePoint)
{
    //TODO calculate actual position
    return mousePoint;
}

void MeleeAbility::createAttack(Point attackPoint)
{
    GameState* gameState = GameState::instance;

    MeleeAttack* attack = new MeleeAttack(attackPoint, attackSprite, 
            playerFriendly, lifetime, 
            damage, user);
    gameState->aliveObjects.push_back(attack);
}
