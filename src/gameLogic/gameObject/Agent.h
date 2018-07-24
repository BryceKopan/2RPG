#ifndef AGENT_H
#define AGENT_H

#include "GameObject.h"

#include "../../util/Vector2.h"
#include "../ability/effects/StatusEffect.h"
#include "../ability/Ability.h"

class StatusEffect;

class Agent : public GameObject
{
    public:
        std::vector<StatusEffect*> statusEffects;
        std::vector<Ability*> abilities;
        Vector2 velocity;
        double speed, maxHealth, timeLastActed, timeLastDamaged;
        bool invisible = false;

        Agent(Point location, double speed , bool collidable, 
                Sprite spritei, int health);

        virtual void update();
        virtual void onObjectCollision(ObjectVector gameObjects);
        virtual void onTileCollision();

        int getHealth();
        void changeHealth(int dHealth);

        void useAbility(int i, Point mousePoint);

        void moveDirect(Vector2 vector);
    private:
        int health;

        void move(Vector2 vector);
        
        Vector2 getAdjustedVelocity(Vector2 velocity);
};

#endif
