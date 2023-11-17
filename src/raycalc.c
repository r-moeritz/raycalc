#define RAYGUI_IMPLEMENTATION

#include "include/raygui.h"
#include "include/calc.h"
#include "include/calcgui.h"

//----------------------------------------------------------------------------------
// Controls Functions Declaration
//----------------------------------------------------------------------------------

static void OnDigitButtonPressed(CalculatorGui* gui, char digit);
static void OnPointButtonPressed(Calculator* calc);
static void OnSignButtonPressed(Calculator* calc);
static void OnEnterButtonPressed(CalculatorGui* gui, Calculator* calc);

static void OnClearButtonPressed(Calculator* calc);
static void OnClearAllButtonPressed(Calculator* calc);

static void OnMemSetButtonPressed(Calculator* calc);
static void OnMemDelButtonPressed(Calculator* calc);
static void OnMemRecallButtonPressed(Calculator* calc);

static void OnAddButtonPressed(CalculatorGui* gui, Calculator* calc);
static void OnSubtractButtonPressed(Calculator* calc);
static void OnMultiplyButtonPressed(Calculator* calc);
static void OnDivideButtonPressed(Calculator* calc);
static void OnSqrtButtonPressed(Calculator* calc);

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main() {
    // Initialization
    //---------------------------------------------------------------------------------------
    int screenWidth = 235;
    int screenHeight = 335;
    bool isDisplayInEditMode = false;
    Calculator* calc = calculator_new();
    if (!calc) return 1;

    CalculatorGui* gui = calculatorgui_new(32);
    if (!gui) {
        calculator_destroy(calc);
        return 1;
    }

    InitWindow(screenWidth, screenHeight, "raycalc");
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

        // raygui: controls drawing
        //----------------------------------------------------------------------------------
        if (GuiTextBox((Rectangle){ 24, 24, 184, 48 }, gui->display, 128, isDisplayInEditMode)) {
            isDisplayInEditMode = !isDisplayInEditMode;
        }

        if (GuiButton((Rectangle){ 24, 80, 40, 32 }, "7")) {
            OnDigitButtonPressed(gui, 7);
        }

        if (GuiButton((Rectangle){ 72, 80, 40, 32 }, "8")) {
            OnDigitButtonPressed(gui, 8);
        }

        if (GuiButton((Rectangle){ 120, 80, 40, 32 }, "9")) {
            OnDigitButtonPressed(gui, 9);
        }

        if (GuiButton((Rectangle){ 168, 80, 40, 32 }, "C")) OnClearButtonPressed(calc);

        if (GuiButton((Rectangle){ 24, 120, 40, 32 }, "4")) {
            OnDigitButtonPressed(gui, 4);
        }

        if (GuiButton((Rectangle){ 72, 120, 40, 32 }, "5")) {
            OnDigitButtonPressed(gui, 5);
        }

        if (GuiButton((Rectangle){ 120, 120, 40, 32 }, "6")) {
            OnDigitButtonPressed(gui, 6);
        }

        if (GuiButton((Rectangle){ 168, 120, 40, 32 }, "AC")) OnClearAllButtonPressed(calc);

        if (GuiButton((Rectangle){ 24, 160, 40, 32 }, "1")) {
            OnDigitButtonPressed(gui, 1);
        }

        if (GuiButton((Rectangle){ 72, 160, 40, 32 }, "2")) {
            OnDigitButtonPressed(gui, 2);
        }

        if (GuiButton((Rectangle){ 120, 160, 40, 32 }, "3")) {
            OnDigitButtonPressed(gui, 3);
        }

        if (GuiButton((Rectangle){ 168, 160, 40, 32 }, "M+")) OnMemSetButtonPressed(calc);

        if (GuiButton((Rectangle){ 24, 240, 40, 32 }, "+")) {
            OnAddButtonPressed(gui, calc);
        }

        if (GuiButton((Rectangle){ 72, 240, 40, 32 }, "-")) OnSubtractButtonPressed(calc);

        if (GuiButton((Rectangle){ 120, 280, 88, 32 }, "ENTER")) {
            OnEnterButtonPressed(gui, calc);
        }

        if (GuiButton((Rectangle){ 168, 240, 40, 32 }, "MR")) OnMemRecallButtonPressed(calc);

        if (GuiButton((Rectangle){ 168, 200, 40, 32 }, "M-")) OnMemDelButtonPressed(calc);

        if (GuiButton((Rectangle){ 24, 280, 40, 32 }, "x")) OnMultiplyButtonPressed(calc);

        if (GuiButton((Rectangle){ 72, 280, 40, 32 }, "/")) OnDivideButtonPressed(calc);

        if (GuiButton((Rectangle){ 24, 200, 40, 32 }, "0")) {
            OnDigitButtonPressed(gui, 0);
        }

        if (GuiButton((Rectangle){ 72, 200, 40, 32 }, ".")) OnPointButtonPressed(calc);

        if (GuiButton((Rectangle){ 120, 240, 40, 32 }, "sqrt")) OnSqrtButtonPressed(calc);

        if (GuiButton((Rectangle){ 120, 200, 40, 32 }, "+/-")) OnSignButtonPressed(calc);
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

//------------------------------------------------------------------------------------
// Controls Functions Definitions (local)
//------------------------------------------------------------------------------------
static void OnDigitButtonPressed(CalculatorGui* gui, char digit) {
    calculatorgui_append(gui, digit);
}

static void OnEnterButtonPressed(CalculatorGui* gui, Calculator* calc) {
    calculator_set_input(calc, gui->value);

    calculatorgui_toggle_clear(gui);
}

static void OnPointButtonPressed(Calculator* calc) {
    // TODO: Implement control logic
}

static void OnSignButtonPressed(Calculator* calc) {
    // TODO: Implement control logic
}

static void OnClearButtonPressed(Calculator* calc) {
    // TODO: Implement control logic
}

static void OnClearAllButtonPressed(Calculator* calc) {
    // TODO: Implement control logic
}

static void OnMemSetButtonPressed(Calculator* calc) {
    // TODO: Implement control logic
}

static void OnMemRecallButtonPressed(Calculator* calc) {
    // TODO: Implement control logic
}

static void OnMemDelButtonPressed(Calculator* calc) {
    // TODO: Implement control logic
}

static void OnAddButtonPressed(CalculatorGui* gui, Calculator* calc) {
    calculator_set_input(calc, gui->value);

    CalculatorResult res;
    calculator_execute(calc, ADDITION, &res);

    if (res.error) {
        // TODO: Display error msg
        return;
    }

    calculatorgui_set(gui, res.value);
}

static void OnSubtractButtonPressed(Calculator* calc) {
    // TODO: Implement control logic
}

static void OnMultiplyButtonPressed(Calculator* calc) {
    // TODO: Implement control logic
}

static void OnDivideButtonPressed(Calculator* calc) {
    // TODO: Implement control logic
}

static void OnSqrtButtonPressed(Calculator* calc) {
    // TODO: Implement control logic
}
