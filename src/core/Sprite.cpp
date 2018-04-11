#include "Sprite.h"

Sprite::Sprite(ALLEGRO_BITMAP* spriteSheet, int spriteWidth, int spriteHeight)
{
    this->spriteSheet = spriteSheet;
    spriteSheetX = 0;
    spriteSheetY = 0;
    this->spriteWidth = spriteWidth;
    this->spriteHeight = spriteHeight;
}

Sprite::Sprite(ALLEGRO_BITMAP* spriteSheet, int spriteSheetX, int spriteSheetY, int spriteWidth, int spriteHeight)
{
    this->spriteSheet = spriteSheet;
    this->spriteSheetX = spriteSheetX;
    this->spriteSheetY = spriteSheetY;
    this->spriteWidth = spriteWidth;
    this->spriteHeight = spriteHeight;
}
