#include "include/display.h"
#include "include/calc.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct DisplayStruct {
    char* buffer;
    size_t size;
    double value;
    bool clear;
};

static void print(Display* dis, const char* message);

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
    snprintf(dis->buffer, dis->size, "%f", value);
}

double display_get_value(Display* dis) {
    if (!dis) return 0;

    return dis->value;
}

void display_append(Display* dis, char digit) {
    if (!dis) return;

    if (dis->value == 0) {
        // Special case for zero
        if (digit == dis->value) return;

        display_set_value(dis, digit);
    }
    else if (dis->clear) {
        display_set_value(dis, digit);
        display_toggle_clear(dis);
    }
    else if (display_is_full(dis)) {
        return;
    }
    else {
        snprintf(dis->buffer, dis->size, "%d%f",
                 (int) dis->value, (double) digit);
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
            print(dis, "E! No result");
            break;

        case ERR_OVERFLOW:
            print(dis, "E! Overflow");
            break;

        case ERR_OUT_OF_MEMORY:
            print(dis, "E! Out of memory");
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
