#ifndef CALCGUI_H
#define CALCGUI_H

#include <stdbool.h>
#include <stddef.h>

typedef struct CalculatorGuiStruct {
    char* display;
    size_t display_size;
    double value;
    bool clear;
} CalculatorGui;

CalculatorGui* calculatorgui_new(size_t display_size);

void calculatorgui_set(CalculatorGui* gui, double value);

void calculatorgui_append(CalculatorGui* gui, char digit);

bool calculatorgui_is_full(CalculatorGui* gui);

void calculatorgui_toggle_clear(CalculatorGui* gui);

#endif
