#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <tuple>
#include <string>
#include <vector>

#include "../BoundingBox.h"
#include "../../graphics/Sprite.h"

class GameObject;

typedef std::vector<GameObject*> ObjectVector;
typedef std::vector<std::tuple<int, int>> TileVector;

class GameObject
{
    public:
        Sprite sprite;
        int x = 0, y = 0;
        bool collidable;

        GameObject(){};
        GameObject(int x, int y, bool collidable, Sprite sprite);

        virtual void update();

        void death();
        void deathCleanup();

        void draw();
        BoundingBox getHitBox();

        virtual void onObjectCollision(ObjectVector gameObjects){};
        virtual void onTileCollision(TileVector tileLocations){};

        ObjectVector getCollidedObjects(BoundingBox hitBox);
        TileVector getCollidedTiles(BoundingBox hitBox);

    private:
        BoundingBox hitBox;
};
#endif
