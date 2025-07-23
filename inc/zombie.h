#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "entity.h"

class Zombie : public Entity
{
private:
    int health;

public:
    Zombie(int difficulty = 0);

    int getHealth() { return health; }
    void takeDamage(int dmg);
};

#endif