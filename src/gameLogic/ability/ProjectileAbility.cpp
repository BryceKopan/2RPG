#include "ProjectileAbility.h"

#include "../gameObject/attack/Projectile.h"
#include "../GameState.h"

ProjectileAbility::ProjectileAbility(GameObject* user, 
        double cooldown, Sprite sprite, bool playerFriendly, 
        double lifetime, int damage, double speed) : 
    AttackAbility(user, cooldown, sprite, playerFriendly, lifetime, 
            damage)
{
    this->speed = speed;
}

Point ProjectileAbility::getAttackLocation(Point mousePoint)
{
    //TODO calculate actual position
    velocity.setPolarCoordinates(1, 
            GameState::instance->player->facingAngle);
    return Point(user->x, user->y);
}

void ProjectileAbility::createAttack(Point attackPoint)
{
    GameState* gameState = GameState::instance;

    Projectile* attack = new Projectile(attackPoint.x, attackPoint.y,
            attackSprite, playerFriendly, lifetime, damage, velocity,
            speed);
    gameState->aliveObjects.push_back(attack);
}
