#include "MeleeAbility.h"

#include "../gameObject/attack/MeleeAttack.h"
#include "../GameState.h"
#include "../../managers/GameManager.h"

MeleeAbility::MeleeAbility(GameObject* user, double cooldown, 
        Sprite sprite, bool playerFriendly, double lifetime,
        int damage) : 
    AttackAbility(user, cooldown, sprite, playerFriendly, lifetime, 
            damage)
{
}

Point MeleeAbility::getAttackLocation(Point mousePoint)
{
    Vector2 vector;
    Point point(GameManager::SCREEN_WIDTH/2,
            GameManager::SCREEN_HEIGHT/2);
    int angle = getAngle(point, mousePoint);
    //TODO Unharcode distance from user
    vector.setPolarCoordinates(24, angle);
    return user->location + vector;
}

void MeleeAbility::createAttack(Point attackPoint)
{
    GameState* gameState = GameState::instance;

    MeleeAttack* attack = new MeleeAttack(attackPoint, attackSprite, 
            playerFriendly, lifetime, 
            damage, user);
    attack->rotate(getAngle(user->location, attackPoint));
    gameState->aliveObjects.push_back(attack);
}
