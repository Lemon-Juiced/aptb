#include "coloro.h" 

void print_red(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, COLOR_RED);
    vfprintf(stderr, fmt, args);
    fprintf(stderr, COLOR_RESET);
    va_end(args);
}

void print_blue(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    printf(COLOR_BLUE);
    vprintf(fmt, args);
    printf(COLOR_RESET);
    va_end(args);
}
