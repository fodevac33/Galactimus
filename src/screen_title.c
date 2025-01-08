#include "raylib.h"
#include "screens.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter = 0;
static int finishScreen = 0;

//----------------------------------------------------------------------------------
// Title Screen Functions Definition
//----------------------------------------------------------------------------------

// Title Screen Initialization logic
void InitTitleScreen(void)
{
    framesCounter = 0;
    finishScreen = 0;
}

// Title Screen Update logic
void UpdateTitleScreen(void)
{
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();
    
    // Calculate menu positions
    Rectangle menuRect = { screenWidth/2 - 150, screenHeight/2 - 150, 300, 300 };
    Rectangle newGameBtn = { menuRect.x + 50, menuRect.y + 100, 200, 40 };
    Rectangle continueBtn = { menuRect.x + 50, menuRect.y + 150, 200, 40 };
    Rectangle settingsBtn = { menuRect.x + 50, menuRect.y + 200, 200, 40 };
    Rectangle exitBtn = { menuRect.x + 50, menuRect.y + 250, 200, 40 };
    
    // Handle button clicks
    if (GuiButton(newGameBtn, "NEW GAME")) {
        // TODO: Implement new game
    }
    if (GuiButton(continueBtn, "CONTINUE")) {
        // TODO: Implement continue
    }
    if (GuiButton(settingsBtn, "SETTINGS")) {
        // TODO: Implement settings
    }
    if (GuiButton(exitBtn, "EXIT")) {
        finishScreen = -1;  // Signal to close the window
    }
}

// Title Screen Draw logic
void DrawTitleScreen(void)
{
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();
    
    // Draw white background
    DrawRectangle(0, 0, screenWidth, screenHeight, WHITE);
    
    // Draw title window
    Rectangle titleRect = { screenWidth/2 - 200, 50, 400, 80 };
    GuiWindowBox(titleRect, "GALACTIMUS");
    
    // Draw menu window
    Rectangle menuRect = { screenWidth/2 - 150, screenHeight/2 - 150, 300, 300 };
    GuiWindowBox(menuRect, "MAIN MENU");
}

// Title Screen Unload logic
void UnloadTitleScreen(void)
{
    // Unload any loaded resources here
}

// Title Screen should finish?
int FinishTitleScreen(void)
{
    return finishScreen;
}
