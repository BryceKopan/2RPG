#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <vector>

#include "player/Player.h"
#include "../graphics/ui/View.h"
#include "../gameLogic/gameObject/GameObject.h"

class GameState
{
    public:
        static GameState* instance;

        bool drawHitBoxes = true;

        Player* player;
        std::vector<GameObject*> aliveObjects;
        std::vector<GameObject*> deadObjects;
        View* currentView;

        //All Defualt Values set in constructor
        GameState();
        ~GameState();
};

#endif
