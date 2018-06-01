#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <string>
#include <vector>

#include "../physics/BoundingBox.h"
#include "../../util/Polygon.h"
#include "../../graphics/Sprite.h"

class GameObject;

typedef std::vector<GameObject*> ObjectVector;

class GameObject
{
    public:
        Sprite sprite;
        double x = 0, y = 0;
        bool collidable;

        GameObject(){};
        GameObject(double x, double y, bool collidable, Sprite sprite);

        virtual void update() = 0;

        void kill();
        void death();

        virtual void draw();
        BoundingBox getHitBox();
        Polygon getHitPoly();

        virtual void onObjectCollision(ObjectVector gameObjects){};
        virtual void onTileCollision(){};

    private:
        bool isAlive = true;

        BoundingBox hitBox;
        Polygon hitPoly;
};
#endif
