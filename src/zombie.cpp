#include "../inc/zombie.h"

Zombie::Zombie(int difficulty) : Entity(GetRandomValue(150, 600), 150, 36, 54) {
    health = 5 + difficulty*0.1;

    loadTexture("../assets/sprites/zombie.png");
}

void Zombie::takeDamage(int dmg) {
    health -= dmg;
}