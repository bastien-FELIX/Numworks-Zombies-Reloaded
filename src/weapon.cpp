#include <cmath>
#include "../inc/weapon.h"

Weapon::Weapon(char* name, char* spritePath, char* reloadPath, char* rakkPath, char* shootPath) : Entity(50, 50, 200, 50) {
    this->name = name;
    loadTexture(spritePath);
    rotation = 0;

    reload = LoadSound(reloadPath);
    rakk = LoadSound(rakkPath);
    shoot = LoadSound(shootPath);
}

void Weapon::loadTexture(char* filePath) {
    Entity::loadTexture(filePath);

    texturePath = filePath;
}

// shows the weapon attached to an entity
void Weapon::display(Entity* e) {
    // vraiment schlag mais ça marche alors osef
    int mouseX = GetMouseX();
    int mouseY = GetMouseY();
    rotation = atan2( (float)(mouseY - e->getPosY() + 20), (float)(mouseX - e->getPosX() + 10)) * 180 / 3.14;

    Texture2D temp = LoadTexture(texturePath);
    int width = temp.width * 3;
    int height = temp.height * 3;

    Rectangle sourceRec = { 0.0, 0.0, (float)temp.width, (float)temp.height };
    Rectangle destRec = { (float)e->getPosX() + 10, (float)e->getPosY() + 20, (float)width, (float)height };
    Vector2 origin = { (float)temp.width, (float)temp.height };

    DrawTexturePro(temp, sourceRec, destRec, origin, rotation, WHITE);
}

void Weapon::playShoot() {
    PlaySound(shoot);
}