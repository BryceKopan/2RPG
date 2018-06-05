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

Location ProjectileAbility::getAttackLocation(double mouseX, double mouseY)
{
    //TODO calculate actual position
    velocity.setPolarCoordinates(1, 
            GameState::instance->player->facingAngle);
    return std::make_tuple(user->x, user->y);
}

void ProjectileAbility::createAttack(Location loc)
{
    GameState* gameState = GameState::instance;

    double x = std::get<0>(loc);
    double y = std::get<1>(loc);
    Projectile* attack = new Projectile(x, y, attackSprite, 
            playerFriendly, lifetime, damage, velocity, speed);
    gameState->aliveObjects.push_back(attack);
}
