#include "Player.h"

#include "../../gameLogic/ability/ProjectileAbility.h"

Player::Player(double x, double y, Sprite sprite) :
    Agent(x, y, 105, true, sprite, 100)
{
    Sprite abilitySprite("res/TestProjectile.png", 10, 10);
    Vector2 velocity;
    velocity.setPolarCoordinates(1, facingAngle);
    ability = new ProjectileAbility(this, .1, abilitySprite, true, 2, 
            40, 100);
}
