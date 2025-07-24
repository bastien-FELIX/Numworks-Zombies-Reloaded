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
    float health;

public:
    Player(int x, int y);

    void movement();
    void setWeapon(Weapon* w);
    void shoot();

    void displayWeapon();
    void displayScore();
    void displayHealth(); // shows a bar, and not some lazy ass text

    int getHealth() { return health; }
    int getScore() { return score; }
    void isDamaged(std::vector<Zombie*> zList);
    void refreshAllBullets(std::vector<Zombie*> zList); // moves, display and test collision (net yet)
};

#endif