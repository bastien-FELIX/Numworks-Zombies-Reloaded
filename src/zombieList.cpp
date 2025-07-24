#include "../inc/zombieList.h"

ZombieList::ZombieList() {
    for (int i = 0; i < 10; i++) {
        spawnZombie();
    }
}

ZombieList::~ZombieList() {
    for (int i = 0; i < zList.size(); i++) {
        delete(zList[i]);
    }
}

void ZombieList::spawnZombie() {
    int rng = GetRandomValue(0, 3);
    int x = 0;
    int y = 0;

    switch (rng)
    {
        case 0:
            x = GetRandomValue(0, GetScreenWidth());
            y = -150;
            break;
        
        case 1:
            x = -150;
            y = GetRandomValue(0, GetScreenHeight());
            break;

        case 2:
            x = GetRandomValue(0, GetScreenWidth());
            y = GetScreenHeight() + 150;
            break;

        case 3:
            x = GetScreenWidth() + 150;
            y = GetRandomValue(0, GetScreenHeight());
            break;

        default:
            x = 50;
            y = 50;
            break;
    }

    zList.push_back(new Zombie(x, y, difficulty));
}

void ZombieList::displayAll() {
    for (int i = 0; i < zList.size(); i++) {
        zList[i]->display();
    }
}

void ZombieList::checkDeadAll() {
    for (int i = 0; i < zList.size(); i++) {
        if (zList[i]->isDead()) {
            zList.erase(zList.begin() + i);
            
            difficulty++;
            spawnZombie();
        }
    }
}

void ZombieList::pathFindAll(Entity* e) {
    for (int i = 0; i < zList.size(); i++) {
        zList[i]->pathFind(e);
    }
}