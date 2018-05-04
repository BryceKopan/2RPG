#ifndef PROJECTILE_TEST_ACTION
#define PROJECTILE_TEST_ACTION

#include "../../gameLogic/action/Action.h"

class ProjectileTestAction : public Action
{
    public:
        ProjectileTestAction(GameObject* user);

    private:
        void doAction();
};

#endif
