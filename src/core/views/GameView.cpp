#include "GameView.h"

#include <math.h>

#include "../../graphics/ui/RectangleElement.h"
#include "../../managers/GameManager.h"
#include "../../managers/LogicManager.h"
#include "../../managers/ResourceManager.h"
#include "../GameState.h"

GameView::GameView()
{
    ALLEGRO_COLOR red = al_map_rgb(255 ,0, 0);
    ALLEGRO_COLOR yellow = al_map_rgb(200, 200, 0);

    elements.push_back(new RectangleElement(20, 20, 110, 30, yellow));
    elements.push_back(new RectangleElement(25, 25, 0, 20, red));
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

    //Update Health Bar
    double percentHP = 
        gameState->player->getHealth() / gameState->player->maxHealth;

    if(RectangleElement* recElement = 
            dynamic_cast<RectangleElement*>(elements[1]))
    {
        recElement->width = 100 * percentHP;
    }
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
            angle = 360 + angle;

        player->facingAngle = angle;
    }
    else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
    {
        //printf("%d\n", event.mouse.button);
        switch(event.mouse.button)
        {
            case 1:
                player->ability->useAbility(event.mouse.x, 
                        event.mouse.y);
                break;
        }
    }
    else if(event.type == ALLEGRO_EVENT_KEY_DOWN)
    {
        switch(event.keyboard.keycode)
        {
            //Movement
            case ALLEGRO_KEY_W:
                player->velocity += Vector2(0, -1);
                break;

            case ALLEGRO_KEY_A:
                player->velocity += Vector2(-1, 0);
                break;

            case ALLEGRO_KEY_S:
                player->velocity += Vector2(0, 1);
                break;

            case ALLEGRO_KEY_D:
                player->velocity += Vector2(1, 0);
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
                player->velocity -= Vector2(0, -1);
                break;

            case ALLEGRO_KEY_A:
                player->velocity -= Vector2(-1, 0);
                break;

            case ALLEGRO_KEY_S:
                player->velocity -= Vector2(0, 1);
                break;

            case ALLEGRO_KEY_D:
                player->velocity -= Vector2(1, 0);
                break;
        }
    }
}
