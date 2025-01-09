#include "raylib.h"
#include "screens.h"

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter = 0;
static int finishScreen = 0;
static float alpha = 0.0f;         // Fade-in alpha value

//----------------------------------------------------------------------------------
// Logo Screen Functions Definition
//----------------------------------------------------------------------------------

// Logo Screen Initialization logic
void InitLogoScreen(void)
{
    finishScreen = 0;
    framesCounter = 0;
    alpha = 0.0f;  // Start fully transparent
}

// Logo Screen Update logic
void UpdateLogoScreen(void)
{
    framesCounter++;
    
    // Fade in over ~160 frames (~2.5 seconds at 60fps)
    if (alpha < 1.0f) {
        alpha += 0.006f;
        if (alpha > 1.0f) alpha = 1.0f;
    }
    
    // After 4 seconds, finish screen
    if (framesCounter > 240) {
        finishScreen = 1;
    }
}

// Logo Screen Draw logic
void DrawLogoScreen(void)
{
    // Clear background to white
    ClearBackground(RAYWHITE);
    
    // Draw centered text with fade-in
    const char* text = "GALACTIMUS";
    int fontSize = 100;
    int textWidth = MeasureText(text, fontSize);
    Vector2 textPosition = {
        GetScreenWidth()/2 - textWidth/2,
        GetScreenHeight()/2 - fontSize/2
    };
    
    DrawText(text, textPosition.x, textPosition.y, fontSize, Fade(BLACK, alpha));
}

// Logo Screen Unload logic
void UnloadLogoScreen(void)
{
    // No resources to unload
}

// Logo Screen should finish?
int FinishLogoScreen(void)
{
    return finishScreen;
}
