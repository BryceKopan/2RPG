#include "Sprite.h"

#include "../managers/ResourceManager.h"

Sprite::Sprite(std::string imagePath, int spriteWidth, int spriteHeight)
{
    this->spriteSheet = ResourceManager::loadBitmap(imagePath);
    this->spriteSheetLocation = Point(0, 0);
    this->spriteWidth = spriteWidth;
    this->spriteHeight = spriteHeight;
}

Sprite::Sprite(std::string imagePath, Point spriteSheetLocation, 
        int spriteWidth, int spriteHeight)
{
    this->spriteSheet = ResourceManager::loadBitmap(imagePath);
    this->spriteSheetLocation = spriteSheetLocation;
    this->spriteWidth = spriteWidth;
    this->spriteHeight = spriteHeight;
}

void Sprite::draw(Point location)
{
    al_draw_bitmap_region(
            spriteSheet,
            spriteSheetLocation.x,
            spriteSheetLocation.y,
            spriteWidth,
            spriteHeight,
            location.x - spriteWidth / 2,
            location.y - spriteHeight / 2,
            0);
}
