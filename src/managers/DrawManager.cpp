#include "DrawManager.h"

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>

#include "GameManager.h"
#include "ResourceManager.h"

void DrawManager::draw()
{
    /*ALLEGRO_FONT* font1 = ResourceManager::loadFont("res/fonts/merienda/Merienda-Regular.ttf", 72);
    ALLEGRO_FONT* font2 = ResourceManager::loadFont("res/fonts/merienda/Merienda-Regular.ttf", 20);
    ALLEGRO_FONT* font3 = ResourceManager::loadFont("res/fonts/merienda/Merienda-Regular.ttf", 40);*/

    ALLEGRO_TRANSFORM transform;

    GameState* gameState = GameState::instance;

    Player* player = gameState->player;

    //Screen Grid
    /*al_draw_line(GameManager::SCREEN_WIDTH/2, 0, 
            GameManager::SCREEN_WIDTH/2, GameManager::SCREEN_HEIGHT,
            al_map_rgb(255, 0, 0), 1);
    al_draw_line(0, GameManager::SCREEN_HEIGHT/2,
            GameManager::SCREEN_WIDTH, GameManager::SCREEN_HEIGHT/2,
            al_map_rgb(255, 0, 0), 1);*/ 

    //Set up transform to set camera over player
    al_identity_transform(&transform);
    al_translate_transform(&transform, 
            (-(player->x + 1)) +
            (GameManager::SCREEN_WIDTH / 2) - 
            (player->sprite.spriteWidth / 2),
            (-(player->y + 1)) + 
            (GameManager::SCREEN_HEIGHT / 2) - 
            (player->sprite.spriteHeight / 2)
            );
    al_use_transform(&transform);

    //Draw TileMap
    gameState->tileMap.draw();

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
    al_identity_transform(&transform);
    al_use_transform(&transform);

    //Draw UI
    gameState->currentView->draw();
}
