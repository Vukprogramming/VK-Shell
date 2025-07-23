#include <stdio.h>
#include "arithmetic.h"

float add_res;
float sub_res;
float mul_res;
float div_res;
char amStr[] = "am -al";
char amStrAA[] = "am -ad";
char amStrSS[] = "am -sb";
char amStrMM[] = "am -ml";
char amStrDD[] = "am -dv";

void add_frs(float a, float b) {
    add_res = a + b;
        printf("Addition: %f\n", add_res);
}

void sub_frs(float a, float b) {
    sub_res = a - b;
        printf("Subtraction: %f\n", sub_res);
}

void mul_frs(float a, float b) {
    mul_res = a * b;
        printf("Multiplication: %f\n", add_res);
}

void div_frs(float a, float b) {
    if (b != 0) {
        div_res = a / b;
    }

    else {
        div_res = 0;
    }
        printf("Division: %f\n", div_res);

}