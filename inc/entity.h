#ifndef ENTITY_H
#define ENTITY_H

#include "raylib.h"

class Entity
{
private:
    int posX, posY;
    int width, height;
    Texture2D texture;

public:
    Entity(int x, int y, int w, int h);
    ~Entity();

    int getPosX() { return posX; }
    int getPosY() { return posY; }
    int getWidth() { return width; }
    int getHeight() { return height; }

    void loadTexture(char* filePath);
    void display();

    void changePos(int deltaX, int deltaY);

    // bool isCollided(int x, int y, int w, int y);
    // bool isCollided(Entity* e);
};

#endif