#include "include/calcgui.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

CalculatorGui* calculatorgui_new(size_t display_size) {
    if (!display_size) return NULL;

    CalculatorGui* gui = malloc(sizeof(CalculatorGui));
    if (!gui) return NULL;


    gui->display = calloc(display_size, sizeof(char));
    if (!gui->display) {
        free(gui);
        return NULL;
    }

    gui->display_size = display_size;

    calculatorgui_set(gui, 0);

    return gui;
}

void calculatorgui_set(CalculatorGui* gui, double value) {
    if (!gui) return;

    gui->value = value;
    snprintf(gui->display, gui->display_size, "%f", value);
}

void calculatorgui_append(CalculatorGui* gui, char digit) {
    if (!gui) return;

    if (gui->value == 0) {
        // Special case for zero
        if (digit == gui->value) return;

        calculatorgui_set(gui, digit);
    }
    else if (gui->clear) {
        calculatorgui_set(gui, digit);
        calculatorgui_toggle_clear(gui);
    }
    else if (calculatorgui_is_full(gui)) {
        return;
    }
    else {
        snprintf(gui->display, gui->display_size, "%d%f",
                 (int) gui->value, (double) digit);
        gui->value = strtod(gui->display, NULL);
    }
}

void calculatorgui_toggle_clear(CalculatorGui* gui) {
    if (!gui) return;

    gui->clear = !gui->clear;
}

bool calculatorgui_is_full(CalculatorGui* gui) {
    if (!gui) return false;

    return strlen(gui->display) == gui->display_size - 1;
}
