#include "DrawManager.h"

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>

#include "GameManager.h"
#include "ResourceManager.h"
#include "../gameLogic/GameState.h"

#include "../util/Util.h"

void DrawManager::draw()
{
    /*ALLEGRO_FONT* font1 = ResourceManager::loadFont("res/fonts/merienda/Merienda-Regular.ttf", 72);
    ALLEGRO_FONT* font2 = ResourceManager::loadFont("res/fonts/merienda/Merienda-Regular.ttf", 20);
    ALLEGRO_FONT* font3 = ResourceManager::loadFont("res/fonts/merienda/Merienda-Regular.ttf", 40);*/
    
    ALLEGRO_TRANSFORM trans;

    GameState* gameState = GameState::instance;

    Player* player = gameState->player;

    //Set up transform to set camera over player
    al_identity_transform(&trans);
    al_translate_transform(&trans, 
            (-(player->location.x + 1)) +
            (GameManager::SCREEN_WIDTH / 2),
            (-(player->location.y + 1)) + 
            (GameManager::SCREEN_HEIGHT / 2));
    al_use_transform(&trans);

    //Draw TileMap
    //al_hold_bitmap_drawing(true);
    gameState->tileMap.draw();
    //al_hold_bitmap_drawing(false);

    //Draw Alive Objects
    for(int i = 0; i < gameState->aliveObjects.size(); i++)
    {
        gameState->aliveObjects[i]->draw();
    }

    //Draw Particles
    /*for(int i = 0; i < gameState->textPool.particleCount; i++)
    {
        TextParticle text = gameState->textPool.pool[i];

        al_draw_text(
                font3, 
                al_map_rgb(text.r, text.g, text.b), 
                text.x, 
                text.y, 
                ALLEGRO_ALIGN_CENTER, 
                text.text.c_str());
    }*/

    //Remove transform
    //Everything after this point x and y limited to screen size
    al_identity_transform(&trans);
    al_use_transform(&trans);

    //Draw UI
    gameState->currentView->draw();

    //Screen Grid
    /*al_draw_line(GameManager::SCREEN_WIDTH/2, 0, 
            GameManager::SCREEN_WIDTH/2, GameManager::SCREEN_HEIGHT,
            al_map_rgb(255, 0, 0), 1);
    al_draw_line(0, GameManager::SCREEN_HEIGHT/2,
            GameManager::SCREEN_WIDTH, GameManager::SCREEN_HEIGHT/2,
            al_map_rgb(255, 0, 0), 1);*/ 
}
