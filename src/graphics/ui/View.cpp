#include "View.h"

void View::processInput(ALLEGRO_EVENT event)
{
    if(event.type == ALLEGRO_EVENT_MOUSE_AXES)
    {
        mousePoint.x = event.mouse.x;
        mousePoint.y = event.mouse.y;
    }
}

void View::draw()
{
    for(int i = 0; i < elements.size(); i++)
    {
        elements[i]->draw();
    }
}

View::~View()
{
    for(int i = 0; i < elements.size(); i++)
    {
        delete elements.at(i);
    }
}
