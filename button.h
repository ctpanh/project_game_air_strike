#ifndef BUTTON__H
#define BUTTON__H

#include "GameObject.h"

class Button : public GameObject
{
public:
    Button();
    ~Button();
    bool input(SDL_Event e);
};
#endif // BUTTON__H
