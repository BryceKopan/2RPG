#include "LogicManager.h"

#include "GameManager.h"
#include "../core/GameState.h"
#include "../core/world/TileMap.h"   

void LogicManager::update()
{
    GameState* gameState = GameState::instance;

    gameState->textPool.update();
    gameState->currentView->update();
}
