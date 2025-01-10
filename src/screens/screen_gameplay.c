#include "raylib.h"
#include "screens.h"
#include <stdlib.h>

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter = 0;
static int finishScreen = 0;

#define GRID_SIZE 10
#define CELL_SIZE 60
#define GRID_OFFSET_X GetScreenWidth() / 2
#define GRID_OFFSET_Y GetScreenHeight() / 2

typedef struct {
    Vector2 position;
    int energy;
} StarSystem;

static StarSystem starSystems[GRID_SIZE][GRID_SIZE];

//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void InitGameplayScreen(void)
{
    framesCounter = 0;
    finishScreen = 0;
    
    // Initialize star systems grid
    for (int x = 0; x < GRID_SIZE; x++) {
        for (int y = 0; y < GRID_SIZE; y++) {
            starSystems[x][y].position = (Vector2){
                (x - GRID_SIZE / 2) * CELL_SIZE + GRID_OFFSET_X, 
                (y - GRID_SIZE / 2) * CELL_SIZE + GRID_OFFSET_Y
            };
            starSystems[x][y].energy = rand() % 100 + 1; // Random energy between 1-100
        }
    }
}

// Gameplay Screen Update logic
void UpdateGameplayScreen(void)
{
    // Check for screen transition
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) {
        finishScreen = 1;
    }
}

// Gameplay Screen Draw logic
void DrawGameplayScreen(void)
{
    // Black background
    ClearBackground(RAYWHITE);

    // First pass: Draw all cells
    for (int x = 0; x < GRID_SIZE; x++) {
        for (int y = 0; y < GRID_SIZE; y++) {
            // Draw cell with border
            DrawRectangleV(starSystems[x][y].position, (Vector2){CELL_SIZE, CELL_SIZE}, WHITE);
            DrawRectangleLinesEx((Rectangle){
                starSystems[x][y].position.x,
                starSystems[x][y].position.y,
                CELL_SIZE,
                CELL_SIZE
            }, 1, GRAY);
        }
    }

    // Second pass: Draw hover effects
    for (int x = 0; x < GRID_SIZE; x++) {
        for (int y = 0; y < GRID_SIZE; y++) {
            // Check for mouse hover
            Vector2 mousePos = GetMousePosition();
            if (CheckCollisionPointRec(mousePos, (Rectangle){
                starSystems[x][y].position.x,
                starSystems[x][y].position.y,
                CELL_SIZE,
                CELL_SIZE
            })) {
                // Draw energy text
                char energyText[16];
                snprintf(energyText, sizeof(energyText), "Energy: %d", starSystems[x][y].energy);
                
                // Calculate text position relative to mouse
                Vector2 textSize = MeasureTextEx(GetFontDefault(), energyText, 20, 1);
                Vector2 textPos = {
                    mousePos.x + 10,
                    mousePos.y - 20
                };
                
                // Draw text
                DrawText(energyText, textPos.x, textPos.y, 20, ORANGE);
            }
        }
    }
}

// Gameplay Screen Unload logic
void UnloadGameplayScreen(void)
{
    // TODO: Unload GAMEPLAY screen variables here!
}

// Gameplay Screen should finish?
int FinishGameplayScreen(void)
{
    return finishScreen;
}
