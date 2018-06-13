#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <string>
#include <vector>

#include "../../util/Polygon.h"
#include "../../graphics/Sprite.h"

class GameObject;

typedef std::vector<GameObject*> ObjectVector;

class GameObject
{
    public:
        Sprite sprite;
        Point location;
        bool collidable;

        GameObject(){};
        GameObject(Point location, bool collidable, Sprite sprite);

        virtual void update() = 0;

        void kill();
        void death();

        virtual void draw();
        Polygon* getHitPoly();

        virtual void onObjectCollision(ObjectVector gameObjects){};
        virtual void onTileCollision(){};

    private:
        bool isAlive = true;

        Polygon hitPoly;
};
#endif
