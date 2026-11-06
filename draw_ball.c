#include "raylib.h"
#include "draw_ball.h"
#include "common.h"

#define screenWidth 800
#define screenHeight 450
#define centerX (screenWidth / 2)
#define centerY (screenHeight / 2)

#define startX 400.0f
#define startY 225.0f
#define ballRadius 20.0f
#define ballSpeed 4.0f
#define boxWidth 60.0f
#define boxHeight 60.0f

static Vector2 ballPosition = {startX, startY};
static Rectangle collision_box = {550.0f, 200.0f, boxWidth, boxHeight};
static int state = G_PLAY;

int BallSetup()
{
    ballPosition = (Vector2){startX, startY};
    state = G_PLAY;
    return state;
}

int BallUpdate()
{
    if (state != G_QUIT)
    {
        if (IsKeyDown(KEY_RIGHT))
            ballPosition.x += ballSpeed;
        if (IsKeyDown(KEY_LEFT))
            ballPosition.x -= ballSpeed;
        if (IsKeyDown(KEY_UP))
            ballPosition.y -= ballSpeed;
        if (IsKeyDown(KEY_DOWN))
            ballPosition.y += ballSpeed;

        if (CheckCollisionCircleRec(ballPosition, ballRadius, collision_box))
        {
            state = G_QUIT;
        }
    }
    else
    {
        if (IsKeyPressed(KEY_ENTER))
        {
            ballPosition = (Vector2){startX, startY};
            state = G_PLAY;
        }
    }

    return state;
}

void BallDraw()
{
    if (state != G_QUIT)
    {
        ClearBackground(RAYWHITE);
        DrawRectangleRec(collision_box, BLUE);
        DrawCircleV(ballPosition, ballRadius, RED);
    }
    else
    {
        ClearBackground(BLACK);
        DrawText("GAME OVER", centerX - 110, centerY - 20, 40, RED);
        DrawText("Press ENTER to Restart", centerX - 110, centerY + 30, 20, DARKGRAY);
    }
}