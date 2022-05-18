#pragma once
#include "GameObject.h"
#include "Bullet.h"

class Enemy : public GameObject {
private:
    bool alive;
    Bullet bullet;
    vector <Bullet*> bulletList;
public:
    Enemy();
    Enemy(SDL_Renderer* renderer, int i);
    ~Enemy();
    void createBullet(SDL_Renderer* renderer);
    void enemyBullet(SDL_Renderer* renderer);
    vector<Bullet*> getBulletList();
    void update(SDL_Renderer* renderer);
    void resetPos();
};

