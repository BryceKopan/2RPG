#include "TestAbility.h"

#include "../../gameLogic/GameState.h"
#include "../../gameLogic/gameObject/attack/Attack.h"

TestAbility::TestAbility(GameObject* user) :
        Ability(user, 2)
{
}

void TestAbility::doAbility(double mouseX, double mouseY)
{
    GameState* gameState = GameState::instance;

    Sprite sprite("res/TestAttack.png", 42, 42);
    Attack* attack = new Attack(user->x - 5, user->y - 5, sprite, 
            true , 1, 50);
    gameState->aliveObjects.push_back(attack);
}
