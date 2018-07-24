#include "Sprite.h"

#include <math.h>

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
    ALLEGRO_TRANSFORM trans, prevTrans;

    // back up the current transform
    al_copy_transform(&prevTrans, al_get_current_transform());

    // scale using the new transform
    al_identity_transform(&trans);
    al_translate_transform(&trans, -location.x, -location.y);
    al_rotate_transform(&trans, rotationAngle * M_PI/180);
    al_translate_transform(&trans, location.x, location.y);
    al_compose_transform(&trans, &prevTrans);
    al_use_transform(&trans);
    
    //set blender
    //al_set_blender(ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA, 
    //        al_map_rgba_f(1, 1, 1, alpha));

    al_draw_bitmap_region(
            spriteSheet,
            spriteSheetLocation.x,
            spriteSheetLocation.y,
            spriteWidth,
            spriteHeight,
            location.x - spriteWidth / 2,
            location.y - spriteHeight / 2,
            0);

    // restore the old transform
    al_use_transform(&prevTrans);
}

void Sprite::rotate(int angle)
{
    rotationAngle = angle;
}

void Sprite::setTransparency(double t)
{
    alpha = t;
}
