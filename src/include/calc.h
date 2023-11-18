#ifndef CALC_H
#define CALC_H

/**
 * @brief The calculator ADT
 */
typedef struct CalculatorStruct Calculator;

/**
 * @brief Operations the calculator can execute
 */
typedef enum CalculatorOperationEnum {
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    CLEAR
} CalculatorOperation;

/**
 * @brief Errors the calculator can encounter
 */
typedef enum CalculatorErrorEnum {
    ERR_OK,
    ERR_NOT_ENOUGH_INPUT,
    ERR_NO_RESULT,
    ERR_OVERFLOW,
    ERR_UNDERFLOW,
    ERR_OUT_OF_MEMORY
} CalculatorError;

/**
 * @brief A structure containing calculator result or an error code
 */
typedef struct CalculatorResultStruct {
    CalculatorError error; /**< Non-zero if the calculator encountered an error */
    double value; /**< Contains the result of the last calculation if error is zero */
} CalculatorResult;

/**
 * @brief Create a new calculator instance.
 *
 * Allocate & initialize a new calculator instance.
 *
 * @return A new calculator instance or NULL on error.
 */
Calculator* calculator_new();

/**
 * @brief Free calculator memory.
 *
 * Calculator is unusable after call.
 *
 * @param calc The calulator instance to destroy
 */
void calculator_destroy(Calculator* calc);

/**
 * @brief Provide input to the calculator.
 *
 * @param calc The calculator instance
 * @param value The input value
 */
void calculator_set_input(Calculator* calc,
                          double value);

/**
 * @brief Get the calculator's latest output value.
 *
 * @param calc The calculator instance
 * @param result A struct that will be filled with the output value or error code
 */
void calculator_get_output(Calculator* calc,
                           CalculatorResult* result);

/**
 * @brief Execute an operation.
 *
 * Attempt to execute an operation. On success, the provided result struct
 * will contain the result, otherwise the error code will be non-zero. If result
 * is NULL then the operation will still be carried out.
 *
 * @param calc The calculator instance
 * @param operation The operation to execute
 * @param result A struct that will be filled with the output value or error code
 */
void calculator_execute(Calculator* calc,
                        CalculatorOperation operation,
                        CalculatorResult* result);

#endif
