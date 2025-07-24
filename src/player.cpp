#include "../inc/player.h"

Player::Player(int x, int y) : Entity(x, y, 36, 54) {
    loadTexture("../assets/sprites/player.png");

    currentWeapon = nullptr;
    score = 0;
    health = 100.0;
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

void Player::shoot() {
    bulletList.push_back(new Bullet(this->getPosX() + 20, this->getPosY() + 20, currentWeapon->getRotation()));
    currentWeapon->playShoot();
}

void Player::displayScore() {
    DrawText(TextFormat("Score : %i", score), 5, 40, 30, BLACK);
}

void Player::displayHealth() {
    DrawRectangle(5, 5, 200, 35, BLACK);                                // border
    DrawRectangle(8, 8, 194, 29, { 169, 50, 38, 255 });                 // background
    DrawRectangle(8, 8, 193 * health/100, 28, GREEN);                   // health bar
}

void Player::isDamaged(std::vector<Zombie*> zList) {
    for (int j = 0; j < zList.size(); j++) {
        if (isCollided(zList[j])) {
            if (health > 0) {
                health--;
            }
        }
    }

    health += 0.1;

    if (health > 100) {
        health = 100;
    }
}

void Player::refreshAllBullets(std::vector<Zombie*> zList) {
    for (int i = 0; i < bulletList.size(); i++) {
        bulletList[i]->move();
        bulletList[i]->display();

        for (int j = 0; j < zList.size(); j++) {
            if (bulletList[i]->isCollided(zList[j]) && zList[j]->getHealth() > 0) {
                score++;

                if (zList[i]->isDead()) {
                    score += 10;
                }

                zList[j]->takeDamage(1);
            }
        }

        if (bulletList[i]->getPosX() + bulletList[i]->getWidth() < 0 || bulletList[i]->getPosX() > GetScreenWidth() || bulletList[i]->getPosY() + bulletList[i]->getHeight() < 0 || bulletList[i]->getPosY() > GetScreenHeight()) {
            bulletList.erase(bulletList.begin() + i);
        }
    }

    isDamaged(zList);
}