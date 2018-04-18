#include "GameView.h"

#include "../../graphics/ui/TextElement.h"
#include "../../managers/GameManager.h"
#include "../../managers/LogicManager.h"
#include "../../managers/ResourceManager.h"
#include "../GameState.h"

GameView::GameView()
{
    ALLEGRO_FONT* font1 = ResourceManager::loadFont("res/fonts/merienda/Merienda-Regular.ttf", 72);
    int screenWidth = GameManager::SCREEN_WIDTH;

    elements.push_back(new TextElement(25, 0, font1, al_map_rgb(0, 255, 0), ALLEGRO_ALIGN_LEFT));

    elements.push_back(new TextElement(screenWidth - 25, 0, font1, al_map_rgb(255, 255, 255), ALLEGRO_ALIGN_RIGHT));
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

    if(event.type == ALLEGRO_EVENT_KEY_DOWN)
    {
        switch(event.keyboard.keycode)
        {
            //Movement
            case ALLEGRO_KEY_W:
                gameState->player->dY = -2;
                break;

            case ALLEGRO_KEY_A:
                gameState->player->dX = -2;
                break;

            case ALLEGRO_KEY_S:
                gameState->player->dY = 2;
                break;

            case ALLEGRO_KEY_D:
                gameState->player->dX = 2;
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
                gameState->player->dY = 0;
                break;

            case ALLEGRO_KEY_A:
                gameState->player->dX = 0;
                break;

            case ALLEGRO_KEY_S:
                gameState->player->dY = 0;
                break;

            case ALLEGRO_KEY_D:
                gameState->player->dX = 0;
                break;
        }
    }
}
