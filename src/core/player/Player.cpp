#include "Player.h"

#include "../abilities/ProjectileTestAbility.h"

Player::Player(double x, double y, Sprite sprite) :
    Agent(x, y, 105, true, sprite, 100)
{
    ability = new ProjectileTestAbility(this);
}
