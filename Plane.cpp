#include "Plane.h"

Plane::Plane(SDL_Renderer* renderer) {
    x = SCREEN_WIDTH/2;
    y = SCREEN_HEIGHT*3/4;
    setPos(x, y);
    setImg(renderer, "Image/plane.png");
    bullet.setImg(renderer, "Image/bullet.png");
    bullet.setPos(x, y);
}

Plane::~Plane() {

}

void Plane::move(SDL_Event event) {
    if(event.type == SDL_MOUSEMOTION) {
        rect.x = event.motion.x - rect.w/2;
        rect.y = event.motion.y - rect.h/2;
    }

    if(event.type == SDL_MOUSEBUTTONDOWN) {
        if(!bullet.is_move()) {
            bullet.setPos(rect.x + rect.w / 2 - 7, rect.y - bullet.getRect().h/2);
            bullet.updateState(true);
        }
    }

}

void Plane::update(SDL_Renderer* renderer) {
    show(renderer);
    if(bullet.is_move()) {
        bullet.attack();
        bullet.show(renderer);
    }
}

SDL_Rect Plane::getRectBullet()
{
    return bullet.getRect();
}
