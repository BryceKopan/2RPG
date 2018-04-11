#include "Player.h"

#include "../../../managers/GameManager.h"
#include "../../../managers/ResourceManager.h"

Player::Player(int x, int y) :
    Agent(x, y)
{
    Sprite sprite(ResourceManager::loadBitmap("res/dungeon1.png"), 96, 192);
    this->sprite = sprite;
}
