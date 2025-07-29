#include <stdio.h>
#include <string.h>
#include "calc.h"

float a;
float b;
float res;

// Additon function
int addf() {
    // Get a
    printf("> ");
    scanf("%f", &a);
    while (getchar() != '\n');
    // Get b
    printf("> ");
    scanf("%f", &b);
    while (getchar() != '\n');

    res = (a + b);

    printf("%f\n", res);

    return 0;
}

// Subtraction function
int subf() {
    // Get a
    printf("> ");
    scanf("%f", &a);
    while (getchar() != '\n');
    // Get b
    printf("> ");
    scanf("%f", &b);
    while (getchar() != '\n');

    res = (a - b);

    printf("%f\n", res);

    return 0;
}

// Multiplication function
int mulf() {
    // Get a
    printf("> ");
    scanf("%f", &a);
    while (getchar() != '\n');
    // Get b
    printf("> ");
    scanf("%f", &b);
    while (getchar() != '\n');

    res = (a * b);

    printf("%f\n", res);

    return 0;
}

// Division function
int divf() {
    // Get a
    printf("> ");
    scanf("%f", &a);
    while (getchar() != '\n');
    // Get b
    printf("> ");
    scanf("%f", &b);
    while (getchar() != '\n');

    res = (a / b);

    printf("%f\n", res);

    return 0;
}