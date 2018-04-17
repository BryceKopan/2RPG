#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <string>

#include "../BoundingBox.h"
#include "../../graphics/Sprite.h"

class GameObject
{
    public:
        Sprite sprite;
        std::string name;
        int x = 0, y = 0;

        GameObject();
        GameObject(int x, int y, Sprite sprite);

        void draw();
        BoundingBox getHitBox();
        virtual void update(){};
};
#endif
