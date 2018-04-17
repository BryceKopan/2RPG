#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <vector>

#include "gameobject/GameObject.h"
#include "gameobject/agent/player/Player.h"
#include "../graphics/ui/View.h"

class GameState
{
    public:
        static GameState* instance;

        Player* player;
        std::vector<GameObject*> aliveObjects;
        std::vector<GameObject*> deadObjects;
        View* currentView;

        //All Defualt Values set in constructor
        GameState();
        ~GameState();
};

#endif
