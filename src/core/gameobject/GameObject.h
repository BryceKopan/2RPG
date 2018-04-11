#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <string>

#include "../Sprite.h"

class GameObject
{
    public:
        Sprite sprite;
        std::string name;
        int x, y;

        GameObject(int x, int y);
};
#endif
