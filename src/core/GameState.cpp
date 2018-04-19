#include "GameState.h"

#include "../gameLogic/gameObject/NPC.h"
#include "views/GameView.h"

GameState* GameState::instance;

GameState::GameState()
{
    currentView = new GameView();
}

GameState::~GameState()
{
    for(int i = 0; i < aliveObjects.size(); i++)
    {
        delete aliveObjects[i];
    }

    for(int i = 0; i < deadObjects.size(); i++)
    {
        delete deadObjects[i];
    }

    delete currentView;
}
