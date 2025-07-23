#ifndef BULLET_H
#define BULLET_H

#define BULLET_SPEED 15

#include "entity.h"

class Bullet : public Entity
{
private:
    int deltaX, deltaY;

public:
    Bullet(int posX, int posY, float rotation);

    void move();
};

#endif