#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "raylibInclude/raylib.h"

// main window
#define WIND_X 500
#define WIND_Y 300

// throtle
#define SIZE_X 200
#define SIZE_Y 100
#define POS_X WIND_X/2 - (SIZE_X/1.5)
#define POS_Y WIND_Y/2 - (SIZE_Y/2)
#define MAX_THROTTLE 1.0f
#define THROTTLE_SPEED 0.1f



void OutOfFocus()
{
    if (!IsWindowFocused())
    {
        SetWindowOpacity(0.7);
    }
    else
    {
        SetWindowOpacity(1);
    }
}

void makeThrottleBody(float* throttle)
{
    // body
    DrawLine(POS_X, POS_Y, POS_X + SIZE_X, POS_Y, WHITE);
    DrawLine(POS_X, POS_Y + SIZE_Y, POS_X + SIZE_X, POS_Y + SIZE_Y, WHITE);

    float pivotX = POS_X + SIZE_X / 2.0f;
    float pivotY = POS_Y + SIZE_Y / 2.0f;

    int length = 90;

    float startX = pivotX;
    float startY = pivotY - length / 2.0f;

    float endX = pivotX;
    float endY = pivotY + length / 2.0f;

    float angle = (*throttle / MAX_THROTTLE) * (PI / 2.0f);

    float s = sinf(angle);
    float c = cosf(angle);

    float rStartX = pivotX + (startX - pivotX) * c - (startY - pivotY) * s;
    float rStartY = pivotY + (startX - pivotX) * s + (startY - pivotY) * c;

    float rEndX = pivotX + (endX - pivotX) * c - (endY - pivotY) * s;
    float rEndY = pivotY + (endX - pivotX) * s + (endY - pivotY) * c;

    DrawLine((int)rStartX, (int)rStartY, (int)rEndX, (int)rEndY, WHITE);
}


int main()
{
    Color current = {20, 20, 20, 1};

    InitWindow(WIND_X, WIND_Y, "Throttle");
    SetTargetFPS(60);

    float throttleInput = 0.0f;
    char throttlePrintBuffer[19] = "";
    int incDec = 0;

    while (!WindowShouldClose())
    {
        // Event
        OutOfFocus();
        if (IsKeyDown(KEY_Q))
        {
            if (throttleInput < 0.1)
            {
                throttleInput += 0.01;
                throttleInput = (throttleInput > 0.1)?0.1:throttleInput;
            }
        }else if(IsKeyDown(KEY_W))
        {
            if (throttleInput < 0.2)
            {
                throttleInput += 0.05;
                throttleInput = (throttleInput > 0.2)?0.2:throttleInput;
            }
        }else if(IsKeyDown(KEY_E))
        {
            if (throttleInput < 0.5)
            {
                throttleInput += 0.075;
                throttleInput = (throttleInput > 0.5)?0.5:throttleInput;
            }
        }else if(IsKeyDown(KEY_R))
        {
            throttleInput += 0.1;
        }else{
            throttleInput -= 0.01;
        }
        
        // Update
        throttleInput = (throttleInput < 0.0f) ? 0.0f : throttleInput;
        throttleInput = (throttleInput > MAX_THROTTLE) ? MAX_THROTTLE : throttleInput;

        sprintf(throttlePrintBuffer, "Throtle Input: %.1f", throttleInput);

        // Draw
        BeginDrawing();
        ClearBackground(current);

        makeThrottleBody(&throttleInput);
        DrawText(throttlePrintBuffer, 20, 20, 20, WHITE);

        EndDrawing();
    }

    CloseWindow();
    exit(0);
}