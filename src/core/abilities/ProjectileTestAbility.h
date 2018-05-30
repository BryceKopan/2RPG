#ifndef PROJECTILE_TEST_ACTION
#define PROJECTILE_TEST_ACTION

#include "../../gameLogic/ability/Ability.h"

class ProjectileTestAbility : public Ability
{
    public:
        ProjectileTestAbility(GameObject* user);

    private:
        void doAbility(double mouseX, double mouseY);
};

#endif
