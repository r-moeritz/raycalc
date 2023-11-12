#define RAYGUI_IMPLEMENTATION

#include "include/raygui.h"
#include "include/stack.h"
#include <stdio.h>
#include <string.h>

typedef struct CalculatorStruct {
    char* displayBuffer;
    size_t displayBufferSize;
    Stack* stack;
    double* memory;
} Calculator;

static void InitCalculator(Calculator* calc, Stack* s, char* buf, size_t bufSiz);

//----------------------------------------------------------------------------------
// Controls Functions Declaration
//----------------------------------------------------------------------------------

static void OnDigitButtonPressed(Calculator* calc, int digit);
static void OnPointButtonPressed(Calculator* calc);
static void OnSignButtonPressed(Calculator* calc);
static void OnEnterButtonPressed(Calculator* calc);

static void OnClearButtonPressed(Calculator* calc);
static void OnClearAllButtonPressed(Calculator* calc);

static void OnMemSetButtonPressed(Calculator* calc);
static void OnMemDelButtonPressed(Calculator* calc);
static void OnMemRecallButtonPressed(Calculator* calc);

static void OnAddButtonPressed(Calculator* calc);
static void OnSubtractButtonPressed(Calculator* calc);
static void OnMultiplyButtonPressed(Calculator* calc);
static void OnDivideButtonPressed(Calculator* calc);
static void OnSqrtButtonPressed(Calculator* calc);

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //---------------------------------------------------------------------------------------
    int screenWidth = 235;
    int screenHeight = 335;
    char displayBuffer[32] = "";
    bool isDisplayInEditMode = false;
    Stack s;
    Calculator calc;

    InitCalculator(&calc, &s, displayBuffer, sizeof(displayBuffer));

    InitWindow(screenWidth, screenHeight, "raycalc");
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Implement required update logic
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

        // raygui: controls drawing
        //----------------------------------------------------------------------------------
        if (GuiTextBox((Rectangle){ 24, 24, 184, 48 }, displayBuffer, 128, isDisplayInEditMode)) {
          isDisplayInEditMode = !isDisplayInEditMode;
        }
        if (GuiButton((Rectangle){ 24, 80, 40, 32 }, "7")) OnDigitButtonPressed(&calc, 7);
        if (GuiButton((Rectangle){ 72, 80, 40, 32 }, "8")) OnDigitButtonPressed(&calc, 8);
        if (GuiButton((Rectangle){ 120, 80, 40, 32 }, "9")) OnDigitButtonPressed(&calc, 9);
        if (GuiButton((Rectangle){ 168, 80, 40, 32 }, "C")) OnClearButtonPressed(&calc);
        if (GuiButton((Rectangle){ 24, 120, 40, 32 }, "4")) OnDigitButtonPressed(&calc, 4);
        if (GuiButton((Rectangle){ 72, 120, 40, 32 }, "5")) OnDigitButtonPressed(&calc, 5);
        if (GuiButton((Rectangle){ 120, 120, 40, 32 }, "6")) OnDigitButtonPressed(&calc, 6);
        if (GuiButton((Rectangle){ 168, 120, 40, 32 }, "AC")) OnClearAllButtonPressed(&calc);
        if (GuiButton((Rectangle){ 24, 160, 40, 32 }, "1")) OnDigitButtonPressed(&calc, 1);
        if (GuiButton((Rectangle){ 72, 160, 40, 32 }, "2")) OnDigitButtonPressed(&calc, 2);
        if (GuiButton((Rectangle){ 120, 160, 40, 32 }, "3")) OnDigitButtonPressed(&calc, 3);
        if (GuiButton((Rectangle){ 168, 160, 40, 32 }, "M+")) OnMemSetButtonPressed(&calc);
        if (GuiButton((Rectangle){ 24, 240, 40, 32 }, "+")) OnAddButtonPressed(&calc);
        if (GuiButton((Rectangle){ 72, 240, 40, 32 }, "-")) OnSubtractButtonPressed(&calc);
        if (GuiButton((Rectangle){ 120, 280, 88, 32 }, "ENTER")) OnEnterButtonPressed(&calc);
        if (GuiButton((Rectangle){ 168, 240, 40, 32 }, "MR")) OnMemRecallButtonPressed(&calc);
        if (GuiButton((Rectangle){ 168, 200, 40, 32 }, "M-")) OnMemDelButtonPressed(&calc);
        if (GuiButton((Rectangle){ 24, 280, 40, 32 }, "x")) OnMultiplyButtonPressed(&calc);
        if (GuiButton((Rectangle){ 72, 280, 40, 32 }, "/")) OnDivideButtonPressed(&calc);
        if (GuiButton((Rectangle){ 24, 200, 40, 32 }, "0")) OnDigitButtonPressed(&calc, 0);
        if (GuiButton((Rectangle){ 72, 200, 40, 32 }, ".")) OnPointButtonPressed(&calc);
        if (GuiButton((Rectangle){ 120, 240, 40, 32 }, "sqrt")) OnSqrtButtonPressed(&calc);
        if (GuiButton((Rectangle){ 120, 200, 40, 32 }, "+/-")) OnSignButtonPressed(&calc);
        //----------------------------------------------------------------------------------

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

static void InitCalculator(Calculator* calc, Stack* s, char* buf, size_t bufSiz)
{
    calc->stack = s;
    calc->displayBuffer = buf;
    calc->displayBufferSize = bufSiz;
    calc->memory = NULL;

    // TODO: Push 0 onto stack & update display buffer.
}

//------------------------------------------------------------------------------------
// Controls Functions Definitions (local)
//------------------------------------------------------------------------------------
static void OnDigitButtonPressed(Calculator* calc, int digit)
{
    if (strlen(calc->displayBuffer) == calc->displayBufferSize-1)
    {
        return;
    }

    // TODO: Special case for 0.

    char str[2];
    snprintf(str, sizeof(str), "%d", digit);

    strncat(calc->displayBuffer, str, 1);
}

static void OnEnterButtonPressed(Calculator* calc)
{
    // TODO: Implement control logic
}

static void OnPointButtonPressed(Calculator* calc)
{
    // TODO: Implement control logic
}

static void OnSignButtonPressed(Calculator* calc)
{
    // TODO: Implement control logic
}

static void OnClearButtonPressed(Calculator* calc)
{
    // TODO: Implement control logic
}

static void OnClearAllButtonPressed(Calculator* calc)
{
    // TODO: Implement control logic
}

static void OnMemSetButtonPressed(Calculator* calc)
{
    // TODO: Implement control logic
}

static void OnMemRecallButtonPressed(Calculator* calc)
{
    // TODO: Implement control logic
}

static void OnMemDelButtonPressed(Calculator* calc)
{
    // TODO: Implement control logic
}

static void OnAddButtonPressed(Calculator* calc)
{
    // TODO: Implement control logic
}

static void OnSubtractButtonPressed(Calculator* calc)
{
    // TODO: Implement control logic
}

static void OnMultiplyButtonPressed(Calculator* calc)
{
    // TODO: Implement control logic
}

static void OnDivideButtonPressed(Calculator* calc)
{
    // TODO: Implement control logic
}

static void OnSqrtButtonPressed(Calculator* calc)
{
    // TODO: Implement control logic
}
