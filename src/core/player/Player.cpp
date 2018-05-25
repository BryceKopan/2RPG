#include "Player.h"

#include "../actions/ProjectileTestAction.h"

Player::Player(double x, double y, Sprite sprite) :
    Agent(x, y, 105, true, sprite, 100)
{
    action = new ProjectileTestAction(this);
}
