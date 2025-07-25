#ifndef WEAPON_H
#define WEAPON_H

#include "entity.h"

class Weapon : public Entity
{
private:
    float rotation;
    char* name;
    char* texturePath;

    Sound shoot;
    // Sound rakk;

    int damage;

public:
    Weapon(char* name, char* spritePath, char* reloadPath, char* rakkPath, char* shootPath);
    ~Weapon();

    void loadTexture(char* filePath);
    void display(Entity* e);
    float getRotation() { return rotation; }

    void playShoot();
    
};

#endif