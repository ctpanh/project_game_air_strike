#ifndef BULLET__H
#define BULLET__H

#include "GameObject.h"

class Bullet : public GameObject {
private:
    int x;
    int y;
    bool isMove;
    int vel;
public:
    Bullet();
    ~Bullet();
    void attack();
    void updateState(bool isMove);
    bool is_move();
};

#endif // BULLET__H
