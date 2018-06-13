#ifndef BLINK_H
#define BLINK_H

#include "../../../gameLogic/ability/Ability.h"
#include "../../../managers/GameManager.h"

class Blink : public Ability
{
    public:
        Blink(GameObject* user, double cooldown, double distance) :
            Ability(user, cooldown), distance(distance){}

        virtual void doAbility(Point mousePoint)
        {
            Vector2 vector;
            Point point(GameManager::SCREEN_WIDTH/2,
                    GameManager::SCREEN_HEIGHT/2);
            int angle = getAngle(point, mousePoint);
            vector.setPolarCoordinates(distance, angle);
            if(Agent* agent = dynamic_cast<Agent*>(user))
                agent->moveDirect(vector);
        }

    private:
        double distance;
};

#endif
