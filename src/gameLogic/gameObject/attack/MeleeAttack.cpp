#include"MeleeAttack.h"

MeleeAttack::MeleeAttack(Point location, Sprite sprite, 
                bool playerFriendly, double lifetime, int damage, 
                GameObject* user) :
    Attack(location, sprite, playerFriendly, lifetime, damage)
{
    this->user = user;
    this->locationOffSet = location - user->location;
}

void MeleeAttack::update()
{
    location = user->location + locationOffSet;
    Attack::update();
}
