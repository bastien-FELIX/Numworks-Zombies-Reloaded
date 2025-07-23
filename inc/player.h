#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

#include "entity.h"
#include "weapon.h"
#include "bullet.h"

class Player : public Entity
{
private:
    Weapon* currentWeapon;
    std::vector<Bullet*> bulletList;

public:
    Player(int x, int y);

    void movement();
    void setWeapon(Weapon* w);
    void displayWeapon();
    void shoot();

    void refreshAllBullets(); // moves, display and test collision (net yet)
};

#endif