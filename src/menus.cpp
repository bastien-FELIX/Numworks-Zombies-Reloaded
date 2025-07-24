#include "../inc/menus.h"

void startMenu() {
    ClearBackground(WHITE);

    int txtWidth = MeasureText("Press SPACE to start", 50);
    DrawText("Press SPACE to start", (GetScreenWidth() - txtWidth)/2, GetScreenHeight()/2 - 150, 50, BLACK);
}

void deadMenu(int score) {
    ClearBackground({ 169, 50, 38, 255 });
    int txtWidth = 0;
    int numOfChoices = 4;

    char** randTxt = new char*[numOfChoices];

    // just in case
    for (int i = 0; i < numOfChoices; i++) {
        randTxt[i] = nullptr;
    }

    randTxt[0] = "Well that's unfortunate";
    randTxt[1] = "Skill issue";
    randTxt[2] = "Git gud";
    randTxt[3] = "The reaper always wins";




    txtWidth = MeasureText(randTxt[score % numOfChoices], 50);
    DrawText(randTxt[score % numOfChoices], (GetScreenWidth() - txtWidth)/2, GetScreenHeight()/2 - 150, 50, BLACK);

    txtWidth = MeasureText(TextFormat("Score : %i", score), 50);
    DrawText(TextFormat("Score : %i", score), (GetScreenWidth() - txtWidth)/2, GetScreenHeight()/2 - 100, 50, BLACK);
}