#include "Projectile.h"

#include "../../core/GameState.h"
#include "../gameObject/NPC.h"
#include "../../core/player/Player.h"

Projectile::Projectile(double x, double y, 
        Vector2 velocity, double speed,
        Sprite sprite, bool playerFriendly, int lifeTime) :
    Attack(x, y, sprite, playerFriendly, lifeTime)
{
    this->velocity = velocity;
    this->speed = speed;
}

void Projectile::update()
{
    move();
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

void Projectile::move()
{
    GameState* gameState = GameState::instance;

    velocity.normalize();

    x += velocity.x * speed * gameState->deltaTime;
    y += velocity.y * speed * gameState->deltaTime;
}
