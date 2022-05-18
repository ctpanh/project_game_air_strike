#include "enemy.h"

Enemy::Enemy()
{
    alive = true;
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

void Enemy::enemyBullet(SDL_Renderer* renderer)
{
    for(int i = 0; i < bulletList.size(); i++)
    {
        Bullet* currentEnemyBullet = bulletList.at(i);
        if(currentEnemyBullet)
        {
            if(currentEnemyBullet->is_move())
            {
                currentEnemyBullet->show(renderer);
                currentEnemyBullet->enemy_bullet();
            }
            else
            {
                currentEnemyBullet->updateState(true);
                currentEnemyBullet->setPos(rect.x + rect.w / 2 - 10, rect.y + rect.h);
            }
        }
    }
}

vector<Bullet*> Enemy::getBulletList()
{
    return bulletList;
}


void Enemy::update(SDL_Renderer* renderer)
{
    if (alive)
    {
        rect.y ++;
        show(renderer);
    }
}

void Enemy::resetPos()
{
    rect.y = - rect.h;
    rect.x = rand() % (SCREEN_WIDTH - rect.w);
}
