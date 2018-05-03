#include "Attack.h"

#include "../../Util.h"
#include "../gameObject/NPC.h"
#include "../../core/GameState.h"

Attack::Attack(int x, int y, Sprite sprite, bool playerFriendly, int lifeTime) :
    GameObject(x, y, false, sprite)
{
    this->playerFriendly = playerFriendly;
    this->lifeTime = lifeTime;
    creationTime = Util::getMillisecondTime();
}

void Attack::update()
{
    long currentTime = Util::getMillisecondTime();

    if(currentTime - creationTime > lifeTime)
        death();
    else
        GameObject::update();
}

void Attack::onObjectCollision(ObjectVector gameObjects)
{
    for(int i = 0; i < gameObjects.size(); i++)
    {
        if(playerFriendly)
        {
            if(dynamic_cast<NPC*>(gameObjects[i]))
            {
                gameObjects[i]->death();
            }
        }
    }
}