#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Attack.h"

#include "../../util/Vector2.h"

class Projectile : public Attack
{
    public:
        Projectile(double x, double y, Vector2 velocity, double speed, 
                Sprite sprite, bool playerFriendly, int lifeTime, 
                int damage);

        virtual void update();

        virtual void onObjectCollision(ObjectVector gameObjects);
        virtual void onTileCollision();
    private:
        Vector2 velocity;
        double speed;

        void move();
};

#endif
