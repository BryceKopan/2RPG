#include "Attack.h"

#include "../../../util/Util.h"
#include "../NPC.h"
#include "../../../core/GameState.h"

Attack::Attack(double x, double y, Sprite sprite, bool playerFriendly, 
        double lifetime, int damage) :
    GameObject(x, y, false, sprite)
{
    this->playerFriendly = playerFriendly;
    this->lifetime = lifetime;
    this->damage = damage;
    creationTime = Util::getPreciseSecondTime();
}

void Attack::update()
{
    double currentTime = Util::getPreciseSecondTime();

    if(currentTime - creationTime > lifetime)
        kill();
}

void Attack::onObjectCollision(ObjectVector gameObjects)
{
    for(int i = 0; i < gameObjects.size(); i++)
    {
        if(playerFriendly)
        {
            if(NPC* npc = dynamic_cast<NPC*>(gameObjects[i]))
            {
                npc->changeHealth(-damage);
            }
        }
    }
}
