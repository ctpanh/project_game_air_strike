#pragma once
#include "GameObject.h"
#include "Bullet.h"

class Plane : public GameObject
{
private:
    int x;
    int y;
    Mix_Chunk* bulletSound;
    Bullet bullet;
public:
    Plane();
    initPlane(SDL_Renderer* renderer);
    ~Plane();
    void move(SDL_Event event);
    void update(SDL_Renderer* renderer);
    Bullet getBullet();
    void clearBullet();
    SDL_Rect getRectBullet();
};

