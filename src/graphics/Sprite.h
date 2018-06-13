#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <allegro5/allegro5.h>

#include "../util/Point.h"

class Sprite
{
    public:
        ALLEGRO_BITMAP* spriteSheet;
        Point spriteSheetLocation;
        int spriteWidth, spriteHeight;

        Sprite(){};
        Sprite(std::string imagePath, int spriteWidth, 
                int spriteHeight);
        Sprite(std::string imagePath, Point spriteSheetLocation, 
                int spriteWidth, int spriteHeight);

        void draw(Point location);
};

#endif
