#include "StatusEffect.h"

#include <algorithm>

#include "../../../util/Util.h"

StatusEffect::StatusEffect(Agent* target, double duration) :
    target(target)
{
    this->startTime = Util::getPreciseSecondTime();
    this->endTime = startTime + duration;
}

void StatusEffect::update()
{
    if(Util::getPreciseSecondTime() >= endTime)
        end();
}

void StatusEffect::start()
{
    target->statusEffects.push_back(this);
}

void StatusEffect::end()
{
    auto it = std::find(target->statusEffects.begin(),
            target->statusEffects.end(), this);
    if(it != target->statusEffects.end())
        target->statusEffects.erase(it);
    delete this;
}
