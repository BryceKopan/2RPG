#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include "../../graphics/ui/View.h"

class GameView : public View
{
    public:
        GameView();

        void draw();
        void update();
        void processInput(ALLEGRO_EVENT event);
    private:
};

#endif
