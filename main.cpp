#include <vector>
#include "raylib.h"

#include "inc/player.h"
#include "inc/weapon.h"
#include "inc/bullet.h"
#include "inc/zombie.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

std::vector<Zombie*> zombieList;

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Numworks Zombies Reloaded");
    InitAudioDevice();
    SetTargetFPS(60);

    Player* p = new Player(50, 50);
    Weapon* w = new Weapon("gex", "../assets/sprites/shotgun.png", "../assets/sfx/shotgun/shotgun_reload.wav", "../assets/sfx/shotgun/shotgun_rakk.wav", "../assets/sfx/shotgun/shotgun_shoot.wav");
    p->setWeapon(w);

    for (int i = 0; i < 15; i++) {
        zombieList.push_back(new Zombie());
    }

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();

        ClearBackground(WHITE);

        p->display();
        p->movement();
        p->displayWeapon();
        p->displayScore();
        p->refreshAllBullets(zombieList);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            p->shoot();
        }

        for (int i = 0; i < zombieList.size(); i++) {
            zombieList[i]->display();
        }

        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
