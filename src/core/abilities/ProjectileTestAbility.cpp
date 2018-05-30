#include "ProjectileTestAbility.h"

#include "../GameState.h"
#include "../../gameLogic/gameObject/attack/Projectile.h"

ProjectileTestAbility::ProjectileTestAbility(GameObject* user) :
    Ability(user, .1)
{
}

void ProjectileTestAbility::doAbility(double mouseX, double mouseY)
{
    GameState* gameState = GameState::instance;

    Vector2 velocity;
    velocity.setPolarCoordinates(1, gameState->player->facingAngle);
    Sprite sprite("res/TestProjectile.png", 10, 10);
    Projectile* attack = new Projectile(user->x + 16, user->y + 16, 
            sprite, true, 2, 40, velocity, 100);
    gameState->aliveObjects.push_back(attack);
}
