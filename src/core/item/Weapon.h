#ifndef WEAPON_H
#define WEAPON_H

#include "Equipment.h"
#include "Slot.h"

//class Agent;

class Weapon : public Equipment
{
    public:
        Weapon(std::string name, Slot slot);
    private:
};

#endif
