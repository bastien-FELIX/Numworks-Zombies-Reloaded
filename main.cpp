#include "raylib.h"

#include "inc/entity.h"
#include "inc/player.h"
#include "inc/weapon.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Numworks Zmbies Reloaded");
    SetTargetFPS(60);

    Player* p = new Player(50, 50);
    Weapon* w = new Weapon("gex", "../assets/sprites/shotgun.png");
    p->setWeapon(w);

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();

        ClearBackground(WHITE);

        p->display();
        p->movement();
        p->displayWeapon();

        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
