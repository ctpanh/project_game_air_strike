#ifndef EXPLOSION__H
#define EXPLOSION__H

#include "GameObject.h"

const int EXPLOSION_WIDTH = 165;
const int EXPLOSION_HEIGHT = 165;

class Explosion : public GameObject
{
public:
    Explosion();
    Explosion(SDL_Renderer* renderer, int i);
    ~Explosion();
};

#endif // EXPLOSION__H
