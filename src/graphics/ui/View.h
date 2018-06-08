#ifndef VIEW_H
#define VIEW_H

#include <vector>
#include <allegro5/allegro5.h>

#include "UIElement.h"
#include "../../util/Point.h"

class View
{
    public:
        ~View();

        void draw();
        virtual void update() = 0;
        virtual void processInput(ALLEGRO_EVENT event);
    protected:
        Point mousePoint;
        std::vector<UIElement*> elements;
};

#endif
