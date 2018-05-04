#include "Player.h"

#include "../actions/ProjectileTestAction.h"

#include "../../Util.h"

Player::Player(int x, int y, Sprite sprite) :
    Agent(x, y, true, sprite)
{
    action = new ProjectileTestAction(this);
}
