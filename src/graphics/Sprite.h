#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <allegro5/allegro5.h>

class Sprite
{
    public:
        ALLEGRO_BITMAP* spriteSheet;
        int spriteSheetX, spriteSheetY, spriteWidth, spriteHeight;

        Sprite(){};
        Sprite(std::string imagePath, int spriteWidth, int spriteHeight);
        Sprite(std::string imagePath, int spriteSheetX, int spriteSheetY, int spriteWidth, int spriteHeight);

        void draw(int x, int y);
};

#endif
