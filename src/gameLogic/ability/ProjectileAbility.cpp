#include "ProjectileAbility.h"

#include "../gameObject/attack/Projectile.h"
#include "../../core/GameState.h"

ProjectileAbility::ProjectileAbility(GameObject* user, double cooldown,
        Sprite sprite, bool playerFriendly, double lifetime,
        int damage, Vector2 velocity, double speed) : 
    AttackAbility(user, cooldown, sprite, playerFriendly, lifetime, 
            damage)
{
    this->velocity = velocity;
    this->speed = speed;
}

Location ProjectileAbility::getAttackLocation(double mouseX, double mouseY)
{
    //TODO calculate actual position
    return std::make_tuple(mouseX, mouseY);
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
