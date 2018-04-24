#ifndef TEST_ACTION_H
#define TEST_ACTION_H

#include "../../gameLogic/action/Action.h"

class TestAction : public Action
{
    public:
        TestAction(GameObject* user);

    private:
        void doAction();
};

#endif
