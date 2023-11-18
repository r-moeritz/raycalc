#ifndef CALCGUI_H
#define CALCGUI_H

#include "calc.h"
#include <stdbool.h>
#include <stddef.h>

/**
 * @brief The display ADT
 */
typedef struct DisplayStruct Display;

/**
 * @brief Create a new display instance
 *
 * Create & initialize a new display instance.
 *
 * @param size The size of the display buffer
 * @return An allocated and initialized display or NULL on error.
 */
Display* display_new(size_t size);

/**
 * @brief Free display memory
 *
 * Display is unusable after call
 *
 * @param dis The display to destroy
 */
void display_destroy(Display* dis);

/**
 * @brief Set the display value
 *
 * Set the display value and fill the display buffer
 *
 * @param dis The display instance
 * @param value The value to display
 */
void display_set_value(Display* dis, double value);

/**
 * @brief Get the display value
 *
 * @param dis The display instance
 * @return The display value
 */
double display_get_value(Display* dis);

/**
 * @brief Append a digit to the display
 *
 * Append a digit to the display buffer
 *
 * @param dis The display instance
 * @param digit The digit to append to the display
 */
void display_append(Display* dis, char digit);

/**
 * @brief Test if the display is full
 *
 * @param dis The display instance
 * @return true if the display is full or false if not
 */
bool display_is_full(Display* dis);

/**
 * @brief Toggle the clear flag on or off
 *
 * Toggle the flag that controls whether the display should be cleared
 * before the next append.
 *
 * @param dis The display instance
 */
void display_toggle_clear(Display* dis);

/**
 * @brief Display an error message
 *
 * Display an error message appropriate to the type of error.
 *
 * @param dis The display instance
 * @param error The type of error encountered
 */
void display_set_error(Display* dis, CalculatorError error);

/**
 * @brief Get the display buffer
 *
 * Expose the display buffer. This should be treated as read-only.
 * Handle with care!
 *
 * @param dis The display instance
 * @return A pointer to the display buffer
 */
char* display_get_buffer(Display* dis);

#endif
