#ifndef DISPLACER_BEAST_H
#define DISPLACER_BEAST_H

#include "../../../gameLogic/gameObject/Player.h"
#include "../../../gameLogic/ability/MeleeAbility.h"
#include "Blink.h"

class DisplacerBeast : public Player
{
    public: 
        DisplacerBeast(Point location, Sprite sprite) : 
            Player(location, sprite)
        {
            Sprite sprite1 = Sprite("res/SmallSwipe.png", 16, 32);
            abilities[0] = new MeleeAbility(this, .1, sprite1, true, 
                    .05, 50);

            abilities[1] = new Blink(this, 1, 128);

            abilities[2] = new Stalk(this, 3, 1.5);

            Sprite sprite2 = Sprite("res/MediumSwipe.png", 16, 64);
            abilities[3] = new MeleeAbility(this, 2, sprite2, true,
                   .2, 100); 
        }
};

#endif
