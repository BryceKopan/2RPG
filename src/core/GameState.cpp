#include "GameState.h"

#include "../gameLogic/gameObject/NPC.h"
#include "views/GameView.h"

GameState* GameState::instance;

GameState::GameState()
{
    Sprite playerSprite("res/dungeon1.png", 96, 192, 32, 32);
    player = new Player(50, 50, playerSprite);
    aliveObjects.push_back(player);

    Sprite goblinSprite("res/dungeon1.png", 64, 192, 32, 32);
    aliveObjects.push_back(new NPC(120, 120, goblinSprite, 100));
    aliveObjects.push_back(new NPC(0, 0, goblinSprite, 30));
    aliveObjects.push_back(new NPC(200, 120, goblinSprite, 30));
    aliveObjects.push_back(new NPC(1000, 20, goblinSprite, 30));

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
