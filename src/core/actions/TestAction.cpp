#include "TestAction.h"

#include "../GameState.h"
#include "../../gameLogic/action/Attack.h"

TestAction::TestAction(GameObject* user) :
    Action(user, 2)
{
}

void TestAction::doAction()
{
    GameState* gameState = GameState::instance;

    Sprite sprite("res/TestAttack.png", 42, 42);
    Attack* attack = new Attack(user->x - 5, user->y - 5, sprite, true , 1);
    gameState->aliveObjects.push_back(attack);
}
