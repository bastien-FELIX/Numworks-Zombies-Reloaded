#ifndef WEAPON_H
#define WEAPON_H

#include "entity.h"

class Weapon : public Entity
{
private:
    float rotation;
    char* name;
    char* texturePath;

public:
    Weapon(char* name, char* spritePath);

    void loadTexture(char* filePath);
    void display(Entity* e);
    
};

#endif