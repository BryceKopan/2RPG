#include "Projectile.h"

#include "../../../core/GameState.h"
#include "../NPC.h"
#include "../../../core/player/Player.h"

Projectile::Projectile(double x, double y, Sprite sprite, 
        bool playerFriendly, int lifetime, int damage, 
        Vector2 velocity, double speed) :
    Attack(x, y, sprite, playerFriendly, lifetime, damage)
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
                kill();
            }
        }
    }
    Attack::onObjectCollision(gameObjects);
}

void Projectile::onTileCollision()
{
    kill();
    Attack::onTileCollision();
}

void Projectile::move()
{
    GameState* gameState = GameState::instance;

    velocity.normalize();

    x += velocity.x * speed * gameState->deltaTime;
    y += velocity.y * speed * gameState->deltaTime;
}