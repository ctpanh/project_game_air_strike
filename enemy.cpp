#include "enemy.h"

Enemy::Enemy()
{
    alive = true;
}

Enemy::Enemy(SDL_Renderer* renderer,int i)
{
    alive = true;
    int x = 100;
    int y = 0;
    setPos(x, y);
    setImg(renderer, "Image/enemy"+to_string(i)+".png");
    bullet.setImg(renderer, "Image/bullet.png");
    bullet.setPos(x, y);
}

Enemy::~Enemy()
{
}

void Enemy::update(SDL_Renderer* renderer)
{
    if (alive)
    {
        rect.y ++;
        show(renderer);
    }
}

void Enemy::dead()
{
    alive = false;
}

bool Enemy::isKilled()
{
    return alive;
}
