#include "../inc/player.h"

Player::Player(int x, int y) : Entity(x, y, 36, 54) {
    loadTexture("../assets/sprites/player.png");

    currentWeapon = nullptr;
}

void Player::movement() {
    int movementSpeed = 8;

    if (IsKeyDown(KEY_Z) || IsKeyDown(KEY_W)) {
        changePos(0, -movementSpeed);
    } if (IsKeyDown(KEY_S)) {
        changePos(0, movementSpeed);
    } if (IsKeyDown(KEY_Q) || IsKeyDown(KEY_A)) {
        changePos(-movementSpeed, 0);
    } if (IsKeyDown(KEY_D)) {
        changePos(movementSpeed, 0);
    }
}

void Player::setWeapon(Weapon* w) {
    currentWeapon = w;
}

void Player::displayWeapon() {
    currentWeapon->display(this);
}