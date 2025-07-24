#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "entity.h"

#define Z_SPEED 3

class Zombie : public Entity
{
private:
    int health;

public:
    Zombie(int difficulty = 0);
    Zombie(int x, int y, int difficulty = 0);

    int getHealth() { return health; }
    void takeDamage(int dmg);
    bool isDead();
    void pathFind(Entity* e); // will move towards this entity
};

#endif