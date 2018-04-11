#ifndef SPRITE_H
#define SPRITE_H

#include <allegro5/allegro5.h>

class Sprite
{
    public:
        ALLEGRO_BITMAP* spriteSheet;
        int spriteSheetX, spriteSheetY, spriteWidth, spriteHeight;

        Sprite(){};
        Sprite(ALLEGRO_BITMAP* spriteSheet, int spriteWidth, int spriteHeight);
        Sprite(ALLEGRO_BITMAP* spriteSheet, int spriteSheetX, int spriteSheetY, int spriteWidth, int spriteHeight);
    private:
};

#endif
