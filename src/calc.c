#include "include/calc.h"
#include "include/stack.h"
#include <stdlib.h>

static void execute(Calculator* calc,
                    CalculatorOperation operation);
static void addition(Calculator* calc);

struct CalculatorStruct {
    CalculatorError error;
    Stack* stack;
};

Calculator* calculator_new() {
    Calculator* calc = malloc(sizeof(Calculator));
    if (!calc) return NULL;

    Stack* stack = malloc(sizeof(Stack));
    if (!stack) {
        free(calc);
        return NULL;
    }
    stack_init(stack, free);

    calc->stack = stack;
    return calc;
}

void calculator_destroy(Calculator* calc) {
    if (!calc) return;

    free(calc->stack);
    free(calc);
}

void calculator_set_input(Calculator* calc, double value) {
    if (!calc) return;

    double* pv = malloc(sizeof(double));
    if (!pv) {
        calc->error = ERR_OUT_OF_MEMORY;
        return;
    }

    *pv = value;
    stack_push(calc->stack, pv);
}

void calculator_get_output(Calculator* calc, CalculatorResult* result) {
    if (!calc || !result) return;

    CalculatorError err = calc->error;
    result->error = err;

    if (err) return;

    double* pv = stack_peek(calc->stack);
    if (!pv) {
        result->error = ERR_NO_RESULT;
        return;
    }

    result->value = *pv;
}

void calculator_execute(Calculator* calc,
                        CalculatorOperation operation,
                        CalculatorResult* result) {
    if (!calc) return;

    execute(calc, operation);

    calculator_get_output(calc, result);
}

static void execute(Calculator* calc, CalculatorOperation operation) {
    switch (operation) {
        case ADDITION:
            addition(calc);
            break;

        default:
            return;
    }
}

static void addition(Calculator* calc) {
    Stack* stack = calc->stack;

    if (stack_size(stack) < 2) {
        calc->error = ERR_NOT_ENOUGH_INPUT;
        return;
    }

    double* sum = malloc(sizeof(double));
    if (!sum) {
        calc->error = ERR_OUT_OF_MEMORY;
        return;
    }

    *sum = 0;
    double* n;

    while (!stack_pop(stack, (void**) &n)) {
        *sum += *n;
        free(n);
    }

    stack_push(stack, sum);
    calc->error = ERR_OK;
}
