#include "Player.h"

#include "../ability/ProjectileAbility.h"

Player::Player(Point location, Sprite sprite) :
    Agent(location , 105, true, sprite, 100)
{}
