#include "ProjectileTestAction.h"

#include "../GameState.h"
#include "../../gameLogic/action/Projectile.h"

ProjectileTestAction::ProjectileTestAction(GameObject* user) :
    Action(user, 10)
{
}

void ProjectileTestAction::doAction()
{
    GameState* gameState = GameState::instance;

    Vector2 velocity(3, 3);
    //velocity.setPolarCoordinates(1, 100);
    Sprite sprite("res/TestProjectile.png", 10, 10);
    Projectile* attack = new Projectile(user->x + 16, user->y + 16, 
            velocity, 100, sprite, true, 2000);
    gameState->aliveObjects.push_back(attack);
}
