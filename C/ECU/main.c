#include <stdio.h>
#include "raylibInclude/raylib.h"

const Color bg = {0, 0, 0};

int main(){
    InitWindow(800, 500, "ECU");
    SetTargetFPS(60);

    int speed = 0;
    int rpm = 0;
    float fuel = 100.0f;

    char speedBuffer[4] = "";
    char rpmBuffer[5] = "";
    char fuelBuffer[5] = "";

    while (!WindowShouldClose())
    {
        sprintf(speedBuffer, "%d", speed);
        sprintf(rpmBuffer, "%d", rpm);
        sprintf(fuelBuffer, "%.1f", fuel);
        
        printf("%s", rpmBuffer);

        // Draw
        BeginDrawing();
        ClearBackground(bg);

        DrawText("RPM", 230, 100, 30, WHITE);
        DrawText("Speed", 503, 100, 30, WHITE);
        DrawText("Fuel", 560, 300, 20, WHITE);

        DrawText(rpmBuffer, 236, 200, 30, WHITE);
        DrawText(speedBuffer, 533, 200, 30, WHITE);
        DrawText(fuelBuffer, 620, 300, 20, WHITE);

        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}