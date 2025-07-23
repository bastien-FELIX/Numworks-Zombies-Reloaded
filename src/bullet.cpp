#include <cmath>
#include "../inc/bullet.h"

Bullet::Bullet(int posX, int posY, float rotation) : Entity(posX, posY, 15, 15) {
    loadTexture("../assets/sprites/bullet.png");

    rotation = rotation * 3.14 / 180;
    deltaX = cos(rotation) * BULLET_SPEED;
    deltaY = sin(rotation) * BULLET_SPEED;
}

void Bullet::move() {
    changePos(deltaX, deltaY);
}