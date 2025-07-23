#ifndef PLAYER_H
#define PLAYER_H

#include <vector>

#include "entity.h"
#include "weapon.h"
#include "bullet.h"
#include "zombie.h"

class Player : public Entity
{
private:
    Weapon* currentWeapon;
    std::vector<Bullet*> bulletList;

    int score;

public:
    Player(int x, int y);

    void movement();
    void setWeapon(Weapon* w);
    void displayWeapon();
    void shoot();
    void displayScore();

    void refreshAllBullets(std::vector<Zombie*> zList); // moves, display and test collision (net yet)
};

#endif