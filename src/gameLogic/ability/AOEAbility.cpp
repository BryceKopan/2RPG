#include "AOEAbility.h"

#include "../gameObject/attack/Attack.h"
#include "../../core/GameState.h"

AOEAbility::AOEAbility(GameObject* user, double cooldown, 
        Sprite sprite, bool playerFriendly, double lifetime,
        int damage) : 
    AttackAbility(user, cooldown, sprite, playerFriendly, lifetime, 
            damage)
{
}

Location AOEAbility::getAttackLocation(double mouseX, double mouseY)
{
    //TODO calculate actual position
    return std::make_tuple(mouseX, mouseY);
}

void AOEAbility::createAttack(Location loc)
{
    GameState* gameState = GameState::instance;

    double x = std::get<0>(loc);
    double y = std::get<1>(loc);
    Attack* attack = new Attack(x, y, attackSprite, playerFriendly, 
            lifetime, damage);
    gameState->aliveObjects.push_back(attack);
}
