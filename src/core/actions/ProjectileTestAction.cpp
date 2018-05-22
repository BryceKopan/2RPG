#include "ProjectileTestAction.h"

#include "../GameState.h"
#include "../../gameLogic/action/Projectile.h"

ProjectileTestAction::ProjectileTestAction(GameObject* user) :
    Action(user, .1)
{
}

void ProjectileTestAction::doAction(int angle)
{
    GameState* gameState = GameState::instance;

    Vector2 velocity;
    velocity.setPolarCoordinates(1, angle);
    Sprite sprite("res/TestProjectile.png", 10, 10);
    Projectile* attack = new Projectile(user->x + 16, user->y + 16, 
            velocity, 100, sprite, true, 2);
    gameState->aliveObjects.push_back(attack);
}
