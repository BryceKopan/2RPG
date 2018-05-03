#include "Player.h"

#include "../actions/TestAction.h"

#include "../../Util.h"

Player::Player(int x, int y, Sprite sprite) :
    Agent(x, y, true, sprite)
{
    action = new TestAction(this);
}
