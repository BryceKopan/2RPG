#include "LogicManager.h"

#include "../core/GameState.h"
#include "../gameLogic/physics/CollisionDetector.h"
#include "../util/Util.h"

double LogicManager::lastFrameTime;

void LogicManager::update()
{
    GameState* gameState = GameState::instance;

    double currentTime = Util::getPreciseSecondTime();
    gameState->deltaTime = currentTime - lastFrameTime;
    lastFrameTime = currentTime;

    //Update all objects
    for(int i = 0; i < gameState->aliveObjects.size(); i++)
    {
        gameState->aliveObjects[i]->update();
        CollisionDetector::resolveCollisions(gameState->aliveObjects[i]);
    }

    //gameState->textPool.update();
    gameState->currentView->update();

    //Cleanup dead objects
    for(int i = 0; i < gameState->deadObjects.size(); i++)
    {
        gameState->deadObjects[i]->death();
    }

    gameState->deadObjects.clear();
}

void LogicManager::initialize()
{
    lastFrameTime = Util::getPreciseSecondTime();
}
