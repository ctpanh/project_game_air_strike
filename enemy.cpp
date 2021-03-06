#include "enemy.h"

Enemy::Enemy()
{
}

Enemy::Enemy(SDL_Renderer* renderer,int i)
{
    setPos(rand() % (SCREEN_WIDTH - rect.w), -rect.h);
    setImg(renderer, "Image/enemy"+to_string(i)+".png");
}

Enemy::~Enemy()
{
}

void Enemy::createBullet(SDL_Renderer* renderer)
{
    Bullet* b = new Bullet;
    b->setImg(renderer, "Image/bulletEnemy.png");
    b->setPos(rect.x + rect.w / 2 - 10, rect.y + rect.h);
    b->updateState(true);

    bulletList.push_back(b);
}

void Enemy::enemyBullet(SDL_Renderer* renderer, int vel)
{
    for(int i = 0; i < bulletList.size(); i++)
    {
        Bullet* b = bulletList.at(i);
        if(b)
        {
            if(b->is_move())
            {
                b->show(renderer);
                b->enemy_bullet(vel);
            }
            else
            {
                b->updateState(true);
                b->setPos(rect.x + rect.w / 2 - 10, rect.y + rect.h);
            }
        }
    }
}

vector<Bullet*> Enemy::getBulletList()
{
    return bulletList;
}


void Enemy::update(SDL_Renderer* renderer, int vel)
{
    rect.y += vel;
    show(renderer);
}

void Enemy::resetPos()
{
    rect.y = - rect.h;
    rect.x = rand() % (SCREEN_WIDTH - rect.w);
}
