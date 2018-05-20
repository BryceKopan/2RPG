#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <vector>

#include "player/Player.h"
#include "../graphics/ui/View.h"
#include "../gameLogic/gameObject/GameObject.h"
#include "../gameLogic/world/TileMap.h"

class GameState
{
    public:
        static GameState* instance;

        bool drawHitBoxes = true;
        double deltaTime = 0;

        TileMap tileMap;

        Player* player;
        ObjectVector aliveObjects, deadObjects;
        View* currentView;

        //All Defualt Values set in constructor
        GameState();
        ~GameState();
};

#endif
