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

    //gameState->textPool.update();
    gameState->currentView->update();

    for(int i = 0; i < gameState->deadObjects.size(); i++)
    {
        gameState->deadObjects[i]->deathCleanup();
    }

    gameState->deadObjects.clear();
}


