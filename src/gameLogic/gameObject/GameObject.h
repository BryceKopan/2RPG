#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <tuple>
#include <string>
#include <vector>

#include "../BoundingBox.h"
#include "../../graphics/Sprite.h"

class GameObject
{
    public:
        Sprite sprite;
        std::string name;
        int x = 0, y = 0;
        BoundingBox hitBox;
        bool collidable;

        GameObject();
        GameObject(int x, int y, bool collidable, Sprite sprite);

        void draw();
        BoundingBox getHitBox();
        virtual void update(){};
        void death();
        virtual void onDeath(){};
        void deathCleanup();

        std::vector<GameObject*> getCollidedObjects(
                std::vector<GameObject*> gameObjects, 
                BoundingBox hitBox);

        bool collidedWithTiles(BoundingBox hitBox);
};
#endif
