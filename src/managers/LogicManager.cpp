#include "LogicManager.h"

#include "GameManager.h"
#include "../core/GameState.h"

void LogicManager::update()
{
    GameState* gameState = GameState::instance;

    for(int i = 0; i < gameState->aliveObjects.size(); i++)
    {
        gameState->aliveObjects[i]->update();
    }

    for(int i = 9; i < gameState->deadObjects.size(); i++)
    {
        gameState->deadObjects[i].deathCleanup();
    }

    gameState->deadObjects.clear();

    //gameState->textPool.update();
    gameState->currentView->update();
}
