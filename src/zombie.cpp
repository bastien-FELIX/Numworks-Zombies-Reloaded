#include "../inc/zombie.h"

Zombie::Zombie(int difficulty) : Entity(GetRandomValue(150, 600), 150, 36, 54) {
    health = 5 + difficulty*0.1;

    loadTexture("../assets/sprites/zombie.png");
}

Zombie::Zombie(int x, int y, int difficulty) : Entity(x, y, 36, 54) {
    health = 5 + difficulty*0.1;

    loadTexture("../assets/sprites/zombie.png");
}

void Zombie::takeDamage(int dmg) {
    health -= dmg;
}

bool Zombie::isDead() {
    if (health <= 0) {
        return true;
    } else {
        return false;
    }
}

void Zombie::pathFind(Entity* e) {
    if (getPosX() > e->getPosX()) {
        changePos(-Z_SPEED, 0);
    } else {
        changePos(Z_SPEED, 0);
    }

    if (getPosY() > e->getPosY()) {
        changePos(0, -Z_SPEED);
    } else {
        changePos(0, Z_SPEED);
    }
}