#include "ProjectileTestAbility.h"

#include "../GameState.h"
#include "../../gameLogic/gameObject/attack/Projectile.h"

ProjectileTestAbility::ProjectileTestAbility(GameObject* user) :
    Ability(user, .1)
{
}

void ProjectileTestAbility::doAbility(int angle)
{
    GameState* gameState = GameState::instance;

    Vector2 velocity;
    velocity.setPolarCoordinates(1, angle);
    Sprite sprite("res/TestProjectile.png", 10, 10);
    Projectile* attack = new Projectile(user->x + 16, user->y + 16, 
            velocity, 100, sprite, true, 2, 40);
    gameState->aliveObjects.push_back(attack);
}
