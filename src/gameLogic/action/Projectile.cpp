#include "Projectile.h"

#include "../gameObject/NPC.h"
#include "../../core/player/Player.h"

Projectile::Projectile(double x, double y, double dX, double dY, 
        Sprite sprite, 
        bool playerFriendly, int lifeTime) :
    Attack(x, y, sprite, playerFriendly, lifeTime)
{
    this->dX = dX;
    this->dY = dY;
}

void Projectile::update()
{
    move(dX, dY);
    Attack::update();
}

void Projectile::onObjectCollision(ObjectVector gameObjects)
{
    for(int i = 0; i < gameObjects.size(); i++)
    {
        if(playerFriendly)
        {
            if(dynamic_cast<NPC*>(gameObjects[i]))
            {
                isAlive = false;
            }
        }
    }
    Attack::onObjectCollision(gameObjects);
}

void Projectile::onTileCollision()
{
    isAlive = false;
    Attack::onTileCollision();
}

void Projectile::move(double dX, double dY)
{
    x += dX;
    y += dY;
}
