#include "include/calc.h"
#include "include/stack.h"
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fenv.h>

typedef double (*BinaryOperator)(double a, double b);

static void execute(Calculator* calc,
                    CalculatorOperation operation);
static void exec_binary_op(Calculator* calc,
                           BinaryOperator op);
static void detect_overflow(BinaryOperator op, double a, double b, CalculatorResult* result);
static double add(double a, double b);
static double subtract(double a, double b);
static double multiply(double a, double b);
static double divide(double a, double b);

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
            exec_binary_op(calc, add);
            break;

        case SUBTRACTION:
            exec_binary_op(calc, subtract);
            break;

        case MULTIPLICATION:
            exec_binary_op(calc, multiply);
            break;

        case DIVISION:
            exec_binary_op(calc, divide);
            break;

        case CLEAR:
            stack_destroy(calc->stack);
            break;
    }
}

static void exec_binary_op(Calculator* calc,
                           BinaryOperator op) {
    Stack* stack = calc->stack;

    if (stack_size(stack) < 2) {
        calc->error = ERR_NOT_ENOUGH_INPUT;
        return;
    }

    CalculatorResult result;
    double* acc = NULL;
    double* n = NULL;

    while (!stack_pop(stack, (void**) &n)) {
        if (acc) {
            detect_overflow(op, *n, *acc, &result);
            if (result.error) {
                calc->error = result.error;
                return;
            }

            *acc = result.value;
            free(n);
        }
        else {
            acc = n;
        }
    }

    stack_push(stack, acc);
    calc->error = ERR_OK;
}

static void detect_overflow(BinaryOperator op,
                            double a,
                            double b,
                            CalculatorResult* result) {
    feclearexcept(FE_OVERFLOW);
    feclearexcept(FE_UNDERFLOW);

    result->value = op(a, b);

    if (fetestexcept(FE_OVERFLOW)) {
        result->error = ERR_OVERFLOW;
    }
    else if (fetestexcept(FE_UNDERFLOW)) {
        result->error = ERR_UNDERFLOW;
    }
    else {
        result->error = ERR_OK;
    }
}

static double add(double a, double b) {
    return a + b;
}

static double subtract(double a, double b) {
    return a - b;
}

static double multiply(double a, double b) {
    return a * b;
}

static double divide(double a, double b) {
    return a / b;
}
