#include "include/display.h"
#include "include/calc.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct DisplayStruct {
    char* buffer;
    size_t size;
    double value;
    bool clear;
    bool point;
    bool decimal;
};

static void print(Display* dis, const char* message);
static void remove_trailing(char* str, char c);

Display* display_new(size_t size) {
    if (!size) return NULL;

    Display* dis = malloc(sizeof(Display));
    if (!dis) return NULL;


    dis->buffer = calloc(size, sizeof(char));
    if (!dis->buffer) {
        free(dis);
        return NULL;
    }

    dis->size = size;

    display_set_value(dis, 0);

    return dis;
}

void display_destroy(Display* dis) {
    if (!dis) return;

    free(dis->buffer);
    free(dis);
}

void display_set_value(Display* dis, double value) {
    if (!dis) return;

    dis->value = value;
    dis->decimal = nearbyint(value) != value;

    if (dis->decimal) {
        snprintf(dis->buffer, dis->size, "%f", value);
        remove_trailing(dis->buffer, '0');
    }
    else {
        snprintf(dis->buffer, dis->size, "%d", (int) value);
    }
}

double display_get_value(Display* dis) {
    if (!dis) return 0;

    return dis->value;
}

void display_append(Display* dis, char digit) {
    if (!dis) return;

    if (digit == '.' && !dis->decimal) {
        // Special case for adding a decimal point to a whole number
        dis->point = true;
    }
    else if (!dis->value) {
        // Special case for zero
        if (digit == dis->value) return;

        if (dis->point) {
            // Append digit after decimal point
            snprintf(dis->buffer, dis->size, "0.%d", digit);
            dis->value = strtod(dis->buffer, NULL);
            dis->point = false;
            dis->decimal = true;
        }
        else {
            // Overwrite value
            display_set_value(dis, digit);
        }
    }
    else if (dis->clear) {
        display_set_value(dis, digit);
        display_toggle_clear(dis);
        dis->point = false;
        dis->decimal = false;
    }
    else if (display_is_full(dis)) {
        return;
    }
    else {
        if (dis->point) {
            snprintf(dis->buffer, dis->size, "%d.%d",
                    (int) dis->value, digit);
            dis->point = false;
            dis->decimal = true;
        }
        else {
            char str[2];
            snprintf(str, sizeof(str), "%d", digit);
            strncat(dis->buffer, str, 1);
        }

        dis->value = strtod(dis->buffer, NULL);
    }
}

void display_toggle_clear(Display* dis) {
    if (!dis) return;

    dis->clear = !dis->clear;
}

bool display_is_full(Display* dis) {
    if (!dis) return false;

    return strlen(dis->buffer) == dis->size - 1;
}

void display_set_error(Display* dis, CalculatorError error) {
    if (!dis) return;

    dis->clear = true;

    switch (error) {
        case ERR_NO_RESULT:
            print(dis, "ERR No result");
            break;

        case ERR_OVERFLOW:
            print(dis, "ERR Overflow");
            break;

        case ERR_UNDERFLOW:
            print(dis, "ERR Underflow");
            break;

        case ERR_OUT_OF_MEMORY:
            print(dis, "ERR Out of memory");
            break;

        default: // ERR_OK, ERR_NOT_ENOUGH_INPUT
            break;
    }
}

char* display_get_buffer(Display* dis) {
    return dis->buffer;
}

static void print(Display* dis, const char* message) {
    snprintf(dis->buffer, dis->size, message);
}

static void remove_trailing(char* str, char c) {
    char* occ = strrchr(str, c);
    while (occ != NULL && occ - str == strlen(str) - 1) {
        *occ = '\0';
        occ = strrchr(str, c);
    }
}
