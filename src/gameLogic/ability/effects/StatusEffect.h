#ifndef STATUS_EFFECT_H
#define STATUS_EFFECT_H

#include "../../gameObject/Agent.h"

class Agent;

class StatusEffect
{
    public:
        StatusEffect(Agent* target, double duration);

        virtual void update();

        virtual void start();
        virtual void end();
    protected:
        Agent* target;
        double startTime, endTime;
};

#endif
