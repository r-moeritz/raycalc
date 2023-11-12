#define RAYGUI_IMPLEMENTATION

#include "include/raygui.h"

//----------------------------------------------------------------------------------
// Controls Functions Declaration
//----------------------------------------------------------------------------------

static void Button0();
static void Button1();
static void Button2();
static void Button3();
static void Button4();
static void Button5();
static void Button6();
static void Button7();
static void Button8();
static void Button9();
static void ButtonPoint();
static void ButtonSign();
static void ButtonEnter();

static void ButtonClear();
static void ButtonClearAll();

static void ButtonMemSet();
static void ButtonMemDel();
static void ButtonMemRecall();

static void ButtonAdd();
static void ButtonSub();
static void ButtonMul();
static void ButtonDiv();
static void ButtonSqrt();

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main()
{
    // Initialization
    //---------------------------------------------------------------------------------------
    int screenWidth = 235;
    int screenHeight = 335;

    InitWindow(screenWidth, screenHeight, "raycalc");

    // raycalc: controls initialization
    //----------------------------------------------------------------------------------
    bool TextBoxScreenEditMode = false;
    char TextBoxScreenText[128] = "0.0000";
    //----------------------------------------------------------------------------------

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
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
        if (GuiTextBox((Rectangle){ 24, 24, 184, 48 }, TextBoxScreenText, 128, TextBoxScreenEditMode)) {
          TextBoxScreenEditMode = !TextBoxScreenEditMode;
        }
        if (GuiButton((Rectangle){ 24, 80, 40, 32 }, "7")) Button7();
        if (GuiButton((Rectangle){ 72, 80, 40, 32 }, "8")) Button8();
        if (GuiButton((Rectangle){ 120, 80, 40, 32 }, "9")) Button9();
        if (GuiButton((Rectangle){ 168, 80, 40, 32 }, "C")) ButtonClear();
        if (GuiButton((Rectangle){ 24, 120, 40, 32 }, "4")) Button4();
        if (GuiButton((Rectangle){ 72, 120, 40, 32 }, "5")) Button5();
        if (GuiButton((Rectangle){ 120, 120, 40, 32 }, "6")) Button6();
        if (GuiButton((Rectangle){ 168, 120, 40, 32 }, "AC")) ButtonClearAll();
        if (GuiButton((Rectangle){ 24, 160, 40, 32 }, "1")) Button1();
        if (GuiButton((Rectangle){ 72, 160, 40, 32 }, "2")) Button2();
        if (GuiButton((Rectangle){ 120, 160, 40, 32 }, "3")) Button3();
        if (GuiButton((Rectangle){ 168, 160, 40, 32 }, "M+")) ButtonMemSet();
        if (GuiButton((Rectangle){ 24, 240, 40, 32 }, "+")) ButtonAdd();
        if (GuiButton((Rectangle){ 72, 240, 40, 32 }, "-")) ButtonSub();
        if (GuiButton((Rectangle){ 120, 280, 88, 32 }, "ENTER")) ButtonEnter();
        if (GuiButton((Rectangle){ 168, 240, 40, 32 }, "MR")) ButtonMemRecall();
        if (GuiButton((Rectangle){ 168, 200, 40, 32 }, "M-")) ButtonMemDel();
        if (GuiButton((Rectangle){ 24, 280, 40, 32 }, "x")) ButtonMul();
        if (GuiButton((Rectangle){ 72, 280, 40, 32 }, "/")) ButtonDiv();
        if (GuiButton((Rectangle){ 24, 200, 40, 32 }, "0")) Button0();
        if (GuiButton((Rectangle){ 72, 200, 40, 32 }, ".")) ButtonPoint();
        if (GuiButton((Rectangle){ 120, 240, 40, 32 }, "sqrt")) ButtonSqrt();
        if (GuiButton((Rectangle){ 120, 200, 40, 32 }, "+/-")) ButtonSign();
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
static void Button0()
{
    // TODO: Implement control logic
}

static void Button1()
{
    // TODO: Implement control logic
}

static void Button2()
{
    // TODO: Implement control logic
}

static void Button3()
{
    // TODO: Implement control logic
}

static void Button4()
{
    // TODO: Implement control logic
}

static void Button5()
{
    // TODO: Implement control logic
}

static void Button6()
{
    // TODO: Implement control logic
}

static void Button7()
{
    // TODO: Implement control logic
}

static void Button8()
{
    // TODO: Implement control logic
}

static void Button9()
{
    // TODO: Implement control logic
}

static void ButtonEnter()
{
    // TODO: Implement control logic
}

static void ButtonPoint()
{
    // TODO: Implement control logic
}

static void ButtonSign()
{
    // TODO: Implement control logic
}

static void ButtonClear()
{
    // TODO: Implement control logic
}

static void ButtonClearAll()
{
    // TODO: Implement control logic
}

static void ButtonMemSet()
{
    // TODO: Implement control logic
}

static void ButtonMemRecall()
{
    // TODO: Implement control logic
}

static void ButtonMemDel()
{
    // TODO: Implement control logic
}

static void ButtonAdd()
{
    // TODO: Implement control logic
}

static void ButtonSub()
{
    // TODO: Implement control logic
}

static void ButtonMul()
{
    // TODO: Implement control logic
}

static void ButtonDiv()
{
    // TODO: Implement control logic
}

static void ButtonSqrt()
{
    // TODO: Implement control logic
}
