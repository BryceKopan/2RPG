#include "GameView.h"

#include <math.h>

#include "../../graphics/ui/RectangleElement.h"
#include "../../graphics/ui/TextElement.h"
#include "../../managers/GameManager.h"
#include "../../managers/LogicManager.h"
#include "../../managers/ResourceManager.h"
#include "../../gameLogic/GameState.h"

GameView::GameView()
{
    ALLEGRO_FONT* font1 = ResourceManager::loadFont("res/fonts/merienda/Merienda-Regular.ttf", 20);
    ALLEGRO_COLOR red = al_map_rgb(255 ,0, 0);
    ALLEGRO_COLOR dirtyYellow = al_map_rgb(200, 200, 0);
    ALLEGRO_COLOR green = al_map_rgb(0, 255, 0);

    elements.push_back(new RectangleElement(20, 20, 110, 30, dirtyYellow));
    elements.push_back(new RectangleElement(25, 25, 0, 20, red));
    elements.push_back(new TextElement(GameManager::SCREEN_WIDTH - 25,
                25, font1, green, ALLEGRO_ALIGN_RIGHT));
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
    ALLEGRO_COLOR red = al_map_rgb(255 ,0, 0);
    ALLEGRO_COLOR yellow = al_map_rgb(255, 255, 0);
    ALLEGRO_COLOR green = al_map_rgb(0, 255, 0);

    //Update Health Bar
    double percentHP = 
        gameState->player->getHealth() / gameState->player->maxHealth;

    if(RectangleElement* recElement = 
            dynamic_cast<RectangleElement*>(elements[1]))
        recElement->width = 100 * percentHP;

    if(TextElement* textElement = 
            dynamic_cast<TextElement*>(elements[2])) 
    {
        if(gameState->showDrawTime)
        {
            double avgDeltaFrameTime = gameState->avgDeltaFrameTime;
            if(avgDeltaFrameTime <= .02)
                textElement->color = green;
            else if(avgDeltaFrameTime <= .033)
                textElement->color = yellow;
            else 
                textElement->color = red;
            textElement->text = 
                std::to_string(avgDeltaFrameTime);
        }
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
