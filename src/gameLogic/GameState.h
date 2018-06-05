#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <vector>

#include "gameObject/Player.h"
#include "gameObject/GameObject.h"
#include "world/TileMap.h"
#include "../graphics/ui/View.h"

class GameState
{
    public:
        static GameState* instance;

        double deltaTime = 0;

        TileMap tileMap;

        Player* player;
        ObjectVector aliveObjects, deadObjects;
        View* currentView;

        //All Defualt Values set in constructor
        GameState();
        ~GameState();

        //debug
        bool drawHitBoxes = true, showDrawTime = true;
        double avgDeltaFrameTime = 0;
};

#endif
