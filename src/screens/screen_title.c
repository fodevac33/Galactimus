#include "raylib.h"
#include "screens.h"

#define RAYGUI_IMPLEMENTATION
#include "../raygui.h"

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
    
    // Calculate button positions using screen-relative sizing
    int buttonWidth = screenWidth * 0.4;  // 40% of screen width
    int buttonHeight = screenHeight * 0.1; // 10% of screen height
    int buttonSpacing = buttonHeight * 0.25; // 25% of button height
    int startY = screenHeight/2 - (4 * buttonHeight + 3 * buttonSpacing)/2;
    
    Rectangle newGameBtn = { screenWidth/2 - buttonWidth/2, startY, buttonWidth, buttonHeight };
    Rectangle continueBtn = { screenWidth/2 - buttonWidth/2, startY + buttonHeight + buttonSpacing, buttonWidth, buttonHeight };
    Rectangle settingsBtn = { screenWidth/2 - buttonWidth/2, startY + 2*(buttonHeight + buttonSpacing), buttonWidth, buttonHeight };
    Rectangle exitBtn = { screenWidth/2 - buttonWidth/2, startY + 3*(buttonHeight + buttonSpacing), buttonWidth, buttonHeight };
    
    // Handle button clicks
    if (GuiButton(newGameBtn, "NEW GAME")) {
        finishScreen = GAMEPLAY;  
    }
    if (GuiButton(continueBtn, "CONTINUE")) {
        // TODO: Implement continue
    }
    if (GuiButton(settingsBtn, "SETTINGS")) {
        finishScreen = OPTIONS;  
    }
    if (GuiButton(exitBtn, "EXIT")) {
        finishScreen = ENDING;  // Signal to close the window
    }
}

// Title Screen Draw logic
void DrawTitleScreen(void)
{
    int screenWidth = GetScreenWidth();
    int screenHeight = GetScreenHeight();
    
    // Draw white background
    DrawRectangle(0, 0, screenWidth, screenHeight, WHITE);
    
    // Draw title text
    const char* title = "GALACTIMUS";
    int titleWidth = MeasureText(title, 60);
    DrawText(title, screenWidth/2 - titleWidth/2, 50, 60, BLACK);
    
    // Draw buttons directly on white background
    int buttonWidth = screenWidth * 0.4;  // 40% of screen width
    int buttonHeight = screenHeight * 0.1; // 10% of screen height
    int buttonSpacing = buttonHeight * 0.25; // 25% of button height
    int startY = screenHeight/2 - (4 * buttonHeight + 3 * buttonSpacing)/2;
    
    Rectangle newGameBtn = { screenWidth/2 - buttonWidth/2, startY, buttonWidth, buttonHeight };
    Rectangle continueBtn = { screenWidth/2 - buttonWidth/2, startY + buttonHeight + buttonSpacing, buttonWidth, buttonHeight };
    Rectangle settingsBtn = { screenWidth/2 - buttonWidth/2, startY + 2*(buttonHeight + buttonSpacing), buttonWidth, buttonHeight };
    Rectangle exitBtn = { screenWidth/2 - buttonWidth/2, startY + 3*(buttonHeight + buttonSpacing), buttonWidth, buttonHeight };
    
    // Set button text size based on button height
    GuiSetStyle(DEFAULT, TEXT_SIZE, buttonHeight * 0.5);
    
    GuiButton(newGameBtn, "NEW GAME");
    GuiButton(continueBtn, "CONTINUE");
    GuiButton(settingsBtn, "SETTINGS");
    GuiButton(exitBtn, "EXIT");
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
