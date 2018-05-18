#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <string>
#include <vector>

#include "../physics/BoundingBox.h"
#include "../../graphics/Sprite.h"

class GameObject;

typedef std::vector<GameObject*> ObjectVector;

class GameObject
{
    public:
        Sprite sprite;
        double x = 0, y = 0;
        bool collidable, isAlive = true;

        GameObject(){};
        GameObject(double x, double y, bool collidable, Sprite sprite);

        virtual void update();

        void death();

        void draw();
        BoundingBox getHitBox();

        virtual void onObjectCollision(ObjectVector gameObjects){};
        virtual void onTileCollision(){};

    private:
        BoundingBox hitBox;
};
#endif
