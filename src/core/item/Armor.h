#ifndef ARMOR_H
#define ARMOR_H

#include "Equipment.h"

class Armor : public Equipment
{
    public:
        Armor(std::string name, Slot slot);
};

#endif
