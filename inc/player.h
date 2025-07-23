#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"
#include "weapon.h"

class Player : public Entity
{
private:
    Weapon* currentWeapon;

public:
    Player(int x, int y);

    void movement();
    void setWeapon(Weapon* w);
    void displayWeapon();
};

#endif