#include "raylib.h"

#include "inc/entity.h"
#include "inc/player.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Numworks Zobmies Reloaded");
    SetTargetFPS(60);

    Player* p = new Player(50, 50);

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();

        ClearBackground(WHITE);

        p->display();
        p->movement();

        EndDrawing();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
