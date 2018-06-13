#include "AOEAbility.h"

#include "../gameObject/attack/Attack.h"
#include "../GameState.h"

AOEAbility::AOEAbility(GameObject* user, double cooldown, 
        Sprite sprite, bool playerFriendly, double lifetime,
        int damage) : 
    AttackAbility(user, cooldown, sprite, playerFriendly, lifetime, 
            damage)
{
}

Point AOEAbility::getAttackLocation(Point mousePoint)
{
    //TODO calculate actual position
    return mousePoint;
}

void AOEAbility::createAttack(Point attackPoint)
{
    GameState* gameState = GameState::instance;

    Attack* attack = new Attack(attackPoint, attackSprite, 
            playerFriendly, lifetime, damage);
    gameState->aliveObjects.push_back(attack);
}
