#pragma once
#include "GameObject.h"
#include "Bullet.h"

class Plane : public GameObject {
private:
    int x;
    int y;
    Bullet bullet;
public:
    Plane(SDL_Renderer* renderer);
    ~Plane();
    void move(SDL_Event event);
    void update(SDL_Renderer* renderer);
    SDL_Rect getRectBullet();
};

