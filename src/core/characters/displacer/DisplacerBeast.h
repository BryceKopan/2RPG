#ifndef DISPLACER_BEAST_H
#define DISPLACER_BEAST_H

#include "../../../gameLogic/gameObject/Player.h"
#include "../../../gameLogic/ability/MeleeAbility.h"

class DisplacerBeast : public Player
{
    public: 
        DisplacerBeast(Point location, Sprite sprite) : 
            Player(location, sprite)
        {
            Sprite sprite1 = Sprite("res/SmallSwipe.png", 16, 32);
            abilities[0] = new MeleeAbility(this, .1, sprite1, true, 
                    .05, 50);
        }
};

#endif
