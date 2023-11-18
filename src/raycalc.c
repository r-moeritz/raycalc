#define RAYGUI_IMPLEMENTATION

#include "include/raygui.h"
#include "include/calc.h"
#include "include/display.h"

static void Calculate(Display* dis, Calculator* calc, CalculatorOperation op);

//----------------------------------------------------------------------------------
// Controls Functions Declaration
//----------------------------------------------------------------------------------

static void OnDigitButtonPressed(Display* dis, char digit);
static void OnPointButtonPressed(Calculator* calc);
static void OnSignButtonPressed(Calculator* calc);
static void OnEnterButtonPressed(Display* dis, Calculator* calc);

static void OnClearButtonPressed(Display* dis, Calculator* calc);
static void OnClearAllButtonPressed(Calculator* calc);

static void OnMemSetButtonPressed(Calculator* calc);
static void OnMemDelButtonPressed(Calculator* calc);
static void OnMemRecallButtonPressed(Calculator* calc);

static void OnAddButtonPressed(Display* dis, Calculator* calc);
static void OnSubtractButtonPressed(Display* dis, Calculator* calc);
static void OnMultiplyButtonPressed(Display* dis, Calculator* calc);
static void OnDivideButtonPressed(Display* dis, Calculator* calc);
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

    Display* dis = display_new(32);
    if (!dis) {
        calculator_destroy(calc);
        return 1;
    }

    InitWindow(screenWidth, screenHeight, "raycalc");
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main loop
    while (!WindowShouldClose()) {  // Detect window close button or ESC key
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

        // raygui: controls drawing
        //----------------------------------------------------------------------------------
        if (GuiTextBox((Rectangle){ 24, 24, 184, 48 }, display_get_buffer(dis), 128, isDisplayInEditMode)) {
            isDisplayInEditMode = !isDisplayInEditMode;
        }

        if (GuiButton((Rectangle){ 24, 80, 40, 32 }, "7")) {
            OnDigitButtonPressed(dis, 7);
        }

        if (GuiButton((Rectangle){ 72, 80, 40, 32 }, "8")) {
            OnDigitButtonPressed(dis, 8);
        }

        if (GuiButton((Rectangle){ 120, 80, 40, 32 }, "9")) {
            OnDigitButtonPressed(dis, 9);
        }

        if (GuiButton((Rectangle){ 168, 80, 40, 32 }, "C")) {
            OnClearButtonPressed(dis, calc);
        }

        if (GuiButton((Rectangle){ 24, 120, 40, 32 }, "4")) {
            OnDigitButtonPressed(dis, 4);
        }

        if (GuiButton((Rectangle){ 72, 120, 40, 32 }, "5")) {
            OnDigitButtonPressed(dis, 5);
        }

        if (GuiButton((Rectangle){ 120, 120, 40, 32 }, "6")) {
            OnDigitButtonPressed(dis, 6);
        }

        if (GuiButton((Rectangle){ 168, 120, 40, 32 }, "AC")) OnClearAllButtonPressed(calc);

        if (GuiButton((Rectangle){ 24, 160, 40, 32 }, "1")) {
            OnDigitButtonPressed(dis, 1);
        }

        if (GuiButton((Rectangle){ 72, 160, 40, 32 }, "2")) {
            OnDigitButtonPressed(dis, 2);
        }

        if (GuiButton((Rectangle){ 120, 160, 40, 32 }, "3")) {
            OnDigitButtonPressed(dis, 3);
        }

        if (GuiButton((Rectangle){ 168, 160, 40, 32 }, "M+")) OnMemSetButtonPressed(calc);

        if (GuiButton((Rectangle){ 24, 240, 40, 32 }, "+")) {
            OnAddButtonPressed(dis, calc);
        }

        if (GuiButton((Rectangle){ 72, 240, 40, 32 }, "-")) {
            OnSubtractButtonPressed(dis, calc);
        }

        if (GuiButton((Rectangle){ 120, 280, 88, 32 }, "ENTER")) {
            OnEnterButtonPressed(dis, calc);
        }

        if (GuiButton((Rectangle){ 168, 240, 40, 32 }, "MR")) OnMemRecallButtonPressed(calc);

        if (GuiButton((Rectangle){ 168, 200, 40, 32 }, "M-")) OnMemDelButtonPressed(calc);

        if (GuiButton((Rectangle){ 24, 280, 40, 32 }, "x")) {
            OnMultiplyButtonPressed(dis, calc);
        }

        if (GuiButton((Rectangle){ 72, 280, 40, 32 }, "/")) {
            OnDivideButtonPressed(dis, calc);
        }

        if (GuiButton((Rectangle){ 24, 200, 40, 32 }, "0")) {
            OnDigitButtonPressed(dis, 0);
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
static void OnDigitButtonPressed(Display* dis, char digit) {
    display_append(dis, digit);
}

static void OnEnterButtonPressed(Display* dis, Calculator* calc) {
    calculator_set_input(calc, display_get_value(dis));

    display_toggle_clear(dis);
}

static void OnPointButtonPressed(Calculator* calc) {
    // TODO: Implement control logic
}

static void OnSignButtonPressed(Calculator* calc) {
    // TODO: Implement control logic
}

static void OnClearButtonPressed(Display* dis, Calculator* calc) {
    calculator_execute(calc, CLEAR, NULL);
    display_set_value(dis, 0);
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

static void OnAddButtonPressed(Display* dis, Calculator* calc) {
    Calculate(dis, calc, ADDITION);
}

static void OnSubtractButtonPressed(Display* dis, Calculator* calc) {
    Calculate(dis, calc, SUBTRACTION);
}

static void OnMultiplyButtonPressed(Display* dis, Calculator* calc) {
    Calculate(dis, calc, MULTIPLICATION);
}

static void OnDivideButtonPressed(Display* dis, Calculator* calc) {
    Calculate(dis, calc, DIVISION);
}

static void OnSqrtButtonPressed(Calculator* calc) {
    // TODO: Implement control logic
}

static void Calculate(Display* dis, Calculator* calc, CalculatorOperation op) {
    calculator_set_input(calc, display_get_value(dis));

    CalculatorResult res;
    calculator_execute(calc, op, &res);

    if (res.error) {
        display_set_error(dis, res.error);
    }
    else {
        display_set_value(dis, res.value);
    }
}
