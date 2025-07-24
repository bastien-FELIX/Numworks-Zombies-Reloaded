#ifndef ZOMBIELIST_H
#define ZOMBIELIST_H

#include <vector>
#include "zombie.h"

class ZombieList
{
private:
    std::vector<Zombie*> zList;
    int difficulty;

public:
    ZombieList();
    ~ZombieList();

    std::vector<Zombie*> getZList() { return zList; }

    void spawnZombie();
    void displayAll();
    void checkDeadAll(); // will respawn a zombie if one is dead
    void pathFindAll(Entity* e);
};

#endif