#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "userVar.h"
#include "cmds.h"
#include "os_detect.h"
#include "arithmetic.h"
#include "ansi.h"

void main_sce(void);

int main() {

    printf("\033[2J\033[H");

    //char userName[256];
    //char userPass[256];

    printf("--------\n");
    printf("VK Shell\n");
    printf("--------\n\n");

    main_sce();

    return 0;
}

    void main_sce(void) {

    float a;
    float b;

    printf("\n%s/> ", userName);
        scanf(" %[^\n]", userIn);

            // Echo command
            if (strcmp(userIn, echoStr) == 0) {
                echof();
                main_sce();
            }
            
            // OS info command
            else if (strcmp(userIn, osInfoStr) == 0) {
                osInfof();
                main_sce();
            }

            // Help command
            else if(strcmp(userIn, helpStr) == 0) {
                helpf();
                main_sce();
            }

            // Clear screen command
            else if (strcmp(userIn, clrsStr) == 0) {
                clrsf();
                main_sce();
            }

            // Change user username command
            else if (strcmp(userIn, chngUserNameStr) == 0) {
                chngUserName();
                main_sce();
            }

            // Change user password command
            else if (strcmp(userIn, chngUserPassStr) == 0) {
                chngUserPass();
                main_sce();
            }

            // Print all user information command
            else if (strcmp(userIn, userEchoStr) == 0) {
                userEcho();
                main_sce();
            }

            // String length command
            else if (strcmp(userIn, strLenStr) == 0) {
                strLenf();
                main_sce();
            }

            // All arithmetic operations command
            else if (strcmp(userIn, amStr) == 0) {
                printf("> ");
                scanf("%f", &a);
                printf("> ");
                scanf("%f", &b);
                    add_frs(a, b);
                    sub_frs(a, b);
                    mul_frs(a, b);
                    div_frs(a, b);
                main_sce();
            }

            // Addtion command
            else if (strcmp(userIn, amStrAA) == 0) {
                printf("> ");
                scanf("%f", &a);
                printf("> ");
                scanf("%f", &b);
                    add_frs(a, b);
                main_sce();  
            }

            // Substraction command
            else if (strcmp(userIn, amStrSS) == 0) {
                printf("> ");
                scanf("%f", &a);
                printf("> ");
                scanf("%f", &b);
                    sub_frs(a, b);
                main_sce();
            }

            // Multiplication command
            else if (strcmp(userIn, amStrMM) == 0) {
                printf("> ");
                scanf("%f", &a);
                printf("> ");
                scanf("%f", &b);
                   mul_frs(a, b);
                main_sce();
            }

            // Divison command
            else if (strcmp(userIn, amStrDD) == 0) {
                printf("> ");
                scanf("%f", &a);
                printf("> ");
                scanf("%f", &b);
                    div_frs(a, b);
                main_sce();
            }

            // Create file command
            else if (strcmp(userIn, crtFlStr) == 0) {
                crtFlf();
                main_sce();
            }

            // Remove file command
            else if (strcmp(userIn, rmStr) == 0) {
                rmf();
                main_sce();
            }

            // Write to file command
                else if (strcmp(userIn, wrtFlStr) == 0) {
                    wrtFl();
                    main_sce();
                } 

            // Exit command
            else if (strcmp(userIn, exitStr) == 0) {
                exitf();
            }            

            // No user input handling
            else if (strlen(userIn) == 0) {
                main_sce();
            }
            // Invalid command
            else {
                printf(COLOR_RED "Error: Invalid command\n" ANSI_RESET);
                main_sce();
            }
        }