#ifndef ARITHMETIC_H
#define ARITHMETIC_H

extern float add_res;
extern float sub_res;
extern float mul_res;
extern float div_res;
extern char amStr[];
extern char amStrAA[];
extern char amStrSS[];
extern char amStrMM[];
extern char amStrDD[];

void add_frs(float a, float b);
void sub_frs(float a, float b);
void mul_frs(float a, float b);
void div_frs(float a, float b);

#endif