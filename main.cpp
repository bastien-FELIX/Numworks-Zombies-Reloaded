#include <vector>
#include "raylib.h"

#include "inc/player.h"
#include "inc/weapon.h"
#include "inc/bullet.h"
#include "inc/zombie.h"
#include "inc/zombieList.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

#ifndef _DEBUG
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#endif 

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Numworks Zombies Reloaded");
    InitAudioDevice();
    SetTargetFPS(60);

    Player* p = new Player(50, 50);
    Weapon* w = new Weapon("gex", "../assets/sprites/shotgun.png", "../assets/sfx/shotgun/shotgun_reload.wav", "../assets/sfx/shotgun/shotgun_rakk.wav", "../assets/sfx/shotgun/shotgun_shoot.wav");
    p->setWeapon(w);

    ZombieList* zl = new ZombieList();
    zl->spawnZombie();

    Music bg_music = LoadMusicStream("../assets/ost/bg_music.mp3");

    PlayMusicStream(bg_music);

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // UpdateMusicStream(bg_music);

        BeginDrawing();

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

        EndDrawing();
    }

    UnloadMusicStream(bg_music);

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
