#pragma once

#include <stdio.h>
#include <stdarg.h>

// ANSI color codes
#define COLOR_RED    "\x1b[31m"
#define COLOR_BLUE   "\x1b[34m"
#define COLOR_RESET  "\x1b[0m"

/**
 * Print to stderr in red.
 * This function should be used for error messages or critical warnings.
 *
 * @param fmt The format string for the message.
 * @param ... The values to format into the string.
 */
void print_red(const char *fmt, ...);

/**
 * Print to stdout in blue.
 * This function should be used for informational messages or prompts.
 *
 * @param fmt The format string for the message.
 * @param ... The values to format into the string.
 */
void print_blue(const char *fmt, ...);