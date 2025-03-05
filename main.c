#include <stdio.h>
#include <raylib.h>

#define WIDTH 1080
#define HEIGHT 720
#define BOID_RADIUS 10
#define BOID_COUNT 5

int main(void)
{
    InitWindow(WIDTH, HEIGHT, "BOIDO");
    Color bg = { .r =23, .g =23, .b = 23, .a =255 };
    while(!WindowShouldClose())
    {
        if (IsKeyDown(KEY_LEFT_CONTROL) && IsKeyPressed(KEY_W)) break;
        BeginDrawing();
        ClearBackground(bg);

        float centerX = GetScreenWidth()/2;
        float centerY = GetScreenHeight()/2;

        for (int i = 0; i < BOID_COUNT; i++)
        {
            DrawCircle((centerX*i)/BOID_COUNT, centerY+i, BOID_RADIUS, RAYWHITE);
        }

        EndDrawing();
    }
    return 0;
}
