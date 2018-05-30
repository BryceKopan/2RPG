#include"MeleeAttack.h"

MeleeAttack::MeleeAttack(double x, double y, Sprite sprite, 
                bool playerFriendly, double lifetime, int damage, 
                GameObject* user) :
    Attack(x, y, sprite, playerFriendly, lifetime, damage)
{
    this->user = user;
    this->xOffSet = x - user->x;
    this->yOffSet = y - user->y;
}

void MeleeAttack::update()
{
    x = user->x + xOffSet;
    y = user->y + yOffSet;
    Attack::update();
}
