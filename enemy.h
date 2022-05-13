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
    void createBullet();
    void enemyBullet(SDL_Renderer* renderer);
    void dead();
    void update(SDL_Renderer* renderer);
    bool isEnemyAlive();
};

