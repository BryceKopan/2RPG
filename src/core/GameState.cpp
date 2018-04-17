#include "GameState.h"

#include "../graphics/ui/GameView.h"

GameState* GameState::instance;

GameState::GameState()
{
    Sprite sprite("res/dungeon1.png", 96, 192, 32, 32);
    player = new Player(50, 50, sprite);
    aliveObjects.push_back(player);
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
