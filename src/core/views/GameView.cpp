#include "GameView.h"

#include <math.h>

#include "../../graphics/ui/TextElement.h"
#include "../../managers/GameManager.h"
#include "../../managers/LogicManager.h"
#include "../../managers/ResourceManager.h"
#include "../GameState.h"

GameView::GameView()
{
}

void GameView::draw()
{
    for(int i = 0; i < elements.size(); i++)
    {
        elements.at(i)->draw();
    }
}

void GameView::update()
{
    GameState* gameState = GameState::instance;
}

void GameView::processInput(ALLEGRO_EVENT event)
{
    GameState* gameState = GameState::instance;
    Player* player = gameState->player;

    if(event.type == ALLEGRO_EVENT_MOUSE_AXES)
    {
        int tanY = (event.mouse.y - (GameManager::SCREEN_HEIGHT/2));
        int tanX = (event.mouse.x - (GameManager::SCREEN_WIDTH/2));
        int angle = atan2(tanY, tanX) * (180/M_PI);

        if(angle < 0)
            angle = 360 - (-angle);

        player->facingAngle = angle;
    }
    else if(event.type == ALLEGRO_EVENT_KEY_DOWN)
    {
        switch(event.keyboard.keycode)
        {
            //Movement
            case ALLEGRO_KEY_W:
                player->dY = -2;
                break;

            case ALLEGRO_KEY_A:
                player->dX = -2;
                break;

            case ALLEGRO_KEY_S:
                player->dY = 2;
                break;

            case ALLEGRO_KEY_D:
                player->dX = 2;
                break;

            //Utility Input
            case ALLEGRO_KEY_F7:
                if(gameState->drawHitBoxes)
                    gameState->drawHitBoxes = false;
                else
                    gameState->drawHitBoxes = true;                
                break;

            case ALLEGRO_KEY_ESCAPE:
                GameManager::isRunning = false;
                break;

            case ALLEGRO_KEY_L:
                break;
        }
    }
    else if(event.type == ALLEGRO_EVENT_KEY_UP)
    {
        switch(event.keyboard.keycode)
        {
            //Movement
            case ALLEGRO_KEY_W:
                player->dY = 0;
                break;

            case ALLEGRO_KEY_A:
                player->dX = 0;
                break;

            case ALLEGRO_KEY_S:
                player->dY = 0;
                break;

            case ALLEGRO_KEY_D:
                player->dX = 0;
                break;
        }
    }
}
