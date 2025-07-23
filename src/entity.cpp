#include "../inc/entity.h"

Entity::Entity(int x, int y, int w, int h) {
    posX = x;
    posY = y;
    width = w;
    height = h;
}

Entity::~Entity() {
    UnloadTexture(texture);
}

void Entity::loadTexture(char* filePath) {
    texture = LoadTexture(filePath);
}

void Entity::display() {
    Rectangle sourceRec = { 0.0, 0.0, (float)texture.width, (float)texture.height };
    Rectangle destRec = { (float)posX, (float)posY, (float)width, (float)height };
    Vector2 origin = { (float)texture.width, (float)texture.height };

    DrawTexturePro(texture, sourceRec, destRec, origin, 0.0, WHITE);
}

void Entity::changePos(int deltaX, int deltaY) {
    posX += deltaX;
    posY += deltaY;
}

bool Entity::isCollided(int x, int y, int w, int h) {
    Rectangle thisRect = { posX, posY, width, height };
    Rectangle theOtherOne = { x, y, w, h };

    // too lazy to make my own
    if (CheckCollisionRecs(thisRect, theOtherOne)) {
        return true;
    } else {
        return false;
    }
}

bool Entity::isCollided(Entity* e) {
    return isCollided(e->getPosX(), e->getPosY(), e->getWidth(), e->getHeight());
}