#include "explosion.h"

Explosion:: Explosion()
{
    rect.w = EXPLOSION_WIDTH;
    rect.h = EXPLOSION_HEIGHT;
}

Explosion::Explosion(SDL_Renderer* renderer,int i)
{
    setImg(renderer, "Image/exp"+to_string(i)+".png");
}

Explosion::~Explosion()
{
}
