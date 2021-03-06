#include "Projectile.h"

#include "../../GameState.h"
#include "../NPC.h"

Projectile::Projectile(Point location, Sprite sprite, 
        bool playerFriendly, int lifetime, int damage, 
        Vector2 velocity, double speed) :
    Attack(location, sprite, playerFriendly, lifetime, damage)
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
    
    Vector2 unit = velocity.getUnitVector();
    location.x += unit.x * speed * gameState->deltaTime;
    location.y += unit.y * speed * gameState->deltaTime;
}
