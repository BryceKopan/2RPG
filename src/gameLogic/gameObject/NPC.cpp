#include "NPC.h"

NPC::NPC(int x, int y, Sprite sprite) :
    Agent(x, y, sprite)
{
}

//Duplicate Agent Update and call npcUpdate
//Done to solve the multi-level hook problem
void NPC::update()
{
    doUpdate();
    npcUpdate();

    x += dX;
    y += dY
}

void NPC:npcUpdate()
{
    
}
