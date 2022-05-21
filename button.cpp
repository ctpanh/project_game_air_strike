#include "button.h"

Button::Button()
{
    rect.h = 100;
    rect.w = 200;
}

Button::~Button()
{

}

bool Button::input(SDL_Event e)
{
    if(e.type == SDL_MOUSEBUTTONDOWN)
    {
        if(e.button.button == SDL_BUTTON_LEFT)
        {
            int x = e.button.x;
            int y = e.button.y;

            if((x > rect.x) && (x < rect.x + rect.w) && (y > rect.y) && (y < rect.y + rect.h))
            {
                return true;
            }
        }
    }
    return false;
}
