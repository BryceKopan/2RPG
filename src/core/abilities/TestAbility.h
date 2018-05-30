#ifndef TEST_ACTION_H
#define TEST_ACTION_H

#include "../../gameLogic/ability/Ability.h"

class TestAbility : public Ability
{
    public:
        TestAbility(GameObject* user);

    private:
        void doAbility(double mouseX, double mouseY);
};

#endif
