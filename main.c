#include "raylib.h"
#include "draw_ball.h"
#include "common.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "MAIN");
    SetTargetFPS(60);

    BallSetup();

    while (!WindowShouldClose())
    {
        BallUpdate();

        BeginDrawing();
        BallDraw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}