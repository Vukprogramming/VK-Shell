#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errors.h"

// Get input macro
#define GET_INPUT(input, size) do {                             \
    printf(" ");                                                \
    if (fgets(input, size, stdin) == NULL) {                       \
        printf("%s\n", ERRORS.input_read_error);                \
        return 1;                                               \
    }                                                           \
    input[strcspn(input, "\n")] = 0;                            \
} while (0)

// Strip newline macro
#define STRIP_NL(var) do {          \
    var[strcspn(var, "\n")] = 0;    \
} while (0)

// Check password macro
#define CHECK_PASS(input, size) do {            \
    printf("Enter your password: ");            \
    if (fgets(input, size, stdin) ==  NULL) {   \
        printf("Error reading input\n");        \
        return 1;                               \
    }                                           \
    input[strcspn(input, "\n")] = 0;            \
} while (0)
