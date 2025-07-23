#ifndef PLAYER_H
#define PLAYER_H

#include "entity.h"

class Player : public Entity
{

public:
    Player(int x, int y);

    void movement();
};

#endif