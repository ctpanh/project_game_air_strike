#include "enemy.h"

Enemy::Enemy()
{
    alive = true;
}

Enemy::Enemy(SDL_Renderer* renderer,int i)
{
    setImg(renderer, "Image/enemy"+to_string(i)+".png");
}

Enemy::~Enemy()
{
}

void Enemy::createBullet(SDL_Renderer* renderer)
{
    Bullet* b = new Bullet;
    b->setImg(renderer, "Image/bullet.png");
    b->setPos(rect.x,rect.y);
    b->updateState(true);
    bulletList.push_back(b);
}

void Enemy::enemyBullet(SDL_Renderer* renderer)
{
    for (int i = 0; i < bulletList.size(); i++)
    {
        Bullet* b = bulletList[i];
        if (b)
        {
            if (b->is_move())
            {
                b->enemy_bullet();
                b->show(renderer);
            }
            else
            {
                b->updateState(true);
                b->setPos(rect.x, rect.y);
            }
        }
    }
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

bool Enemy::isEnemyAlive()
{
    return alive;
}
