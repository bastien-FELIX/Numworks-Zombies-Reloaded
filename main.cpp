#include <vector>
#include "raylib.h"

#include "inc/player.h"
#include "inc/weapon.h"
#include "inc/bullet.h"
#include "inc/zombie.h"
#include "inc/zombieList.h"
#include "inc/menus.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Numworks Zombies Reloaded");
    InitAudioDevice();
    SetTargetFPS(60);

    Player* p = new Player(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
    Weapon* w = new Weapon("gex", "../assets/sprites/shotgun.png", "../assets/sfx/shotgun/shotgun_reload.wav", "../assets/sfx/shotgun/shotgun_rakk.wav", "../assets/sfx/shotgun/shotgun_shoot.wav");
    p->setWeapon(w);

    ZombieList* zl = new ZombieList();
    zl->spawnZombie();

    Music bg_music = LoadMusicStream("../assets/ost/bg_music.ogg");

    short gameStarted = -1; // -1 is not started yet, 0 is over, 1 is in game

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        UpdateMusicStream(bg_music);

        BeginDrawing();

        switch (gameStarted) {
            case -1:
                startMenu();

                if (IsKeyPressed(KEY_SPACE)) {
                    gameStarted = 1;
                    PlayMusicStream(bg_music);
                }

                break;

            case 0:
                deadMenu(p->getScore());

                if (IsKeyPressed(KEY_SPACE)) {
                    p = new Player(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
                    p->setWeapon(w);

                    zl = new ZombieList();
                    zl->spawnZombie();

                    gameStarted = 1;

                    PlayMusicStream(bg_music);
                }

                break;

            case 1:
                ClearBackground(WHITE);

                p->display();
                p->movement();
                p->displayWeapon();
                p->displayScore();
                p->displayHealth();
                p->refreshAllBullets(zl->getZList());

                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    p->shoot();
                }

                zl->checkDeadAll();
                zl->pathFindAll(p);
                zl->displayAll();

                if (p->getHealth() <= 0) {
                    gameStarted = 0;
                    StopMusicStream(bg_music);
                }

                break;
        }

        EndDrawing();
    }

    UnloadMusicStream(bg_music);

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
