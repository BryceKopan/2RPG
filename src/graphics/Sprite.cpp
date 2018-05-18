#include "Sprite.h"

#include "../managers/ResourceManager.h"

Sprite::Sprite(std::string imagePath, int spriteWidth, int spriteHeight)
{
    this->spriteSheet = ResourceManager::loadBitmap(imagePath);
    spriteSheetX = 0;
    spriteSheetY = 0;
    this->spriteWidth = spriteWidth;
    this->spriteHeight = spriteHeight;
}

Sprite::Sprite(std::string imagePath, int spriteSheetX, int spriteSheetY, int spriteWidth, int spriteHeight)
{
    this->spriteSheet = ResourceManager::loadBitmap(imagePath);
    this->spriteSheetX = spriteSheetX;
    this->spriteSheetY = spriteSheetY;
    this->spriteWidth = spriteWidth;
    this->spriteHeight = spriteHeight;
}

void Sprite::draw(double x, double y)
{
    al_draw_bitmap_region(
            spriteSheet,
            spriteSheetX,
            spriteSheetY,
            spriteWidth,
            spriteHeight,
            x,
            y,
            0);
}
