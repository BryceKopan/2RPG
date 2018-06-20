#ifndef INVISBLE_H
#define INVISBLE_H

#include "StatusEffect.h"

class Invisible : public StatusEffect
{
    public:
        Invisible(Agent* target, double duration) :
            StatusEffect(target, duration){}

        virtual void update()
        {
            if(startTime < target->timeLastDamaged ||
                    startTime < target->timeLastActed)
                end();

            StatusEffect::update();
        }

        virtual void start()
        {
            if(Agent* agent = dynamic_cast<Agent*>(target))
            {
                agent->invisible = true;
            }

            StatusEffect::start();
        }

        virtual void end()
        {
            if(Agent* agent = dynamic_cast<Agent*>(target))
            {
                agent->invisible = false;
            }

            StatusEffect::end();
        }
};

#endif
