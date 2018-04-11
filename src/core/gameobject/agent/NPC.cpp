#include "NPC.h"

#include "../../GameState.h"
#include "../../../managers/ResourceManager.h"

NPC::NPC(int x, int y) :
    Agent(x, y),
    ai(3)
{
    Sprite sprite(ResourceManager::loadBitmap("res/dungeon1.png"), 64, 192);
    this->sprite = sprite;
}
