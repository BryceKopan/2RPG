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
    GameState* gameState = GameState::instance;

    long currentTime = Util::getMillisecondTime();

    if(currentTime - creationTime > lifeTime)
    {
        death();
    }
    else
    {
        doUpdate();

        std::vector<GameObject*> collidedObjects = 
            getCollidedObjects(gameState->aliveObjects, hitBox);

        for(int i = 0; i < collidedObjects.size(); i++)
        {
            if(playerFriendly)
            {
                if(dynamic_cast<NPC*>(collidedObjects[i]))
                {
                    collidedObjects[i]->death();
                }
            }
        }
    }
}
