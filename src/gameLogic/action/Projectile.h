#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Attack.h"

class Projectile : public Attack
{
    public:
        Projectile(double x, double y, double dX, double dY, 
                Sprite sprite, bool playerFriendly, int lifeTime);

        virtual void update();

        virtual void onObjectCollision(ObjectVector gameObjects);
        virtual void onTileCollision();
    private:
        double dX, dY;

        void move(double dX, double dY);
};

#endif
