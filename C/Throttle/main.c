#include "raylibInclude/raylib.h"

void OutOfFocus()
{
    if (!IsWindowFocused())
    {
        SetWindowOpacity(0.5);
    }
    else
    {
        SetWindowOpacity(1);
    }
}

int main()
{
    InitWindow(500, 500, "Throttle");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        OutOfFocus();

        EndDrawing();
    }

    return 0;
}