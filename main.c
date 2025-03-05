#include <stdio.h>
#include <raylib.h>

#define WIDTH 1080
#define HEIGHT 720
#define BOID_RADIUS 10
#define BOID_COUNT 5

typedef struct {
    // positions
    float x;
    float y;

    // veloctiess
    float vx;
    float vy;
} boid_t;



boid_t create_boid(Vector2 position);
void create_boids(void);

int main(void)
{
    InitWindow(WIDTH, HEIGHT, "BOIDO");
    Color bg = { .r =23, .g =23, .b = 23, .a =255 };

    Vector2 pos = {
        .x = GetScreenWidth()/2,
        .y = GetScreenHeight()/2
    };
    boid_t boid = create_boid(pos);

    while(!WindowShouldClose())
    {
        if (IsKeyDown(KEY_LEFT_CONTROL) && IsKeyPressed(KEY_W)) break;
        BeginDrawing();
        ClearBackground(bg);

        boid.x += boid.vx;
        boid.y += boid.vy;

        if (boid.x+ BOID_RADIUS >= GetRenderWidth() || boid.x-BOID_RADIUS < 0)  { boid.vx *= -1; }
        if (boid.y +BOID_RADIUS >= GetRenderHeight() || boid.y-BOID_RADIUS < 0) { boid.vy *= -1; }

        DrawCircle(boid.x, boid.y, BOID_RADIUS, RAYWHITE);

        EndDrawing();
    }
    return 0;
}


boid_t create_boid(Vector2 position)
{
    Vector2 velocity = { .x = 2.0, .y = -4.0};
    boid_t created = {
        .x = position.x,
        .y = position.y,
        .vx = velocity.x,
        .vy = velocity.y
    };

    return created;
}
