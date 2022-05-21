#include "Bullet.h"

Bullet::Bullet() {
    x = 0;
    y = 0;
    rect.w = 15;
    rect.h = 50;
    isMove = false;
    vel = 10;
}

Bullet::~Bullet() {

}

void Bullet::attack() {
    rect.y -= vel;
    if(rect.y < -rect.h) {
        isMove = false;
    }
}

void Bullet::enemy_bullet(int vel)
{
    rect.y += vel/2;
    if (rect.y > SCREEN_HEIGHT + rect.h)
    {
        isMove = false;
    }
}

void Bullet::updateState(bool isMove) {
    this->isMove = isMove;
}

bool Bullet::is_move()
{
    return isMove;
}
