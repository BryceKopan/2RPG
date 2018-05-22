#include "Player.h"

#include "../actions/ProjectileTestAction.h"

Player::Player(double x, double y, Sprite sprite) :
    Agent(x, y, 105, true, sprite)
{
    action = new ProjectileTestAction(this);
}
