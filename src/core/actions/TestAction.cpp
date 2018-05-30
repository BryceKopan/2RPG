#include "TestAction.h"

#include "../GameState.h"
#include "../../gameLogic/gameObject/attack/Attack.h"

TestAction::TestAction(GameObject* user) :
    Action(user, 2)
{
}

void TestAction::doAction(int angle)
{
    GameState* gameState = GameState::instance;

    Sprite sprite("res/TestAttack.png", 42, 42);
    Attack* attack = new Attack(user->x - 5, user->y - 5, sprite, 
            true , 1, 50);
    gameState->aliveObjects.push_back(attack);
}
