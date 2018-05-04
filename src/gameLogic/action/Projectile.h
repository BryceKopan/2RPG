#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Attack.h"

class Projectile : public Attack
{
    public:
        Projectile(int x, int y, int dX, int dY, Sprite sprite, bool playerFriendly, int lifeTime);

        virtual void update();

        virtual void onObjectCollision(ObjectVector gameObjects);
        virtual void onTileCollision();
    private:
        int dX, dY;

        void move(int dX, int dY);
};

#endif
