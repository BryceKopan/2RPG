#include "Projectile.h"

#include "../gameObject/NPC.h"
#include "../../core/player/Player.h"

Projectile::Projectile(int x, int y, int dX, int dY, Sprite sprite, 
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
    for(int i; i < gameObjects.size(); i++)
    {
        if(playerFriendly)
        {
            if(dynamic_cast<NPC*>(gameObjects[i]))
            {
                gameObjects[i]->death();
                death();
            }
        }
        else 
        {
            if(dynamic_cast<Player*>(gameObjects[i]))
            {
                gameObjects[i]->death();
                death();
            }
        }
    }
    Attack::onObjectCollision(gameObjects);
}

void Projectile::onTileCollision()
{
    death();
    Attack::onTileCollision();
}

void Projectile::move(int dX, int dY)
{
    x += dX;
    y += dY;
}
