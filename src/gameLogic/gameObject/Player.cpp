#include "Player.h"

#include "../ability/ProjectileAbility.h"

Player::Player(Point location, Sprite sprite) :
    Agent(location , 105, true, sprite, 100)
{
    Sprite abilitySprite("res/TestProjectile.png", 10, 10);
    Vector2 velocity;
    velocity.setPolarCoordinates(1, facingAngle);
    abilities[0] = new ProjectileAbility(this, 0, abilitySprite, true,
            2, 40, 100);
}
