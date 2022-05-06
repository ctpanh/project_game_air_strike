#pragma once
#include "GameObject.h"
#include "Bullet.h"

class Enemy : public GameObject {
private:
    int x;
    int y;
    bool alive;
    Bullet bullet;
public:
    Enemy();
    Enemy(SDL_Renderer* renderer, int i);
    ~Enemy();
    void dead();
    void update(SDL_Renderer* renderer);
    bool isKilled();
};

