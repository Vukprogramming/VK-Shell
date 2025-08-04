#include <stdio.h>
#include <string.h>
#include "user.h"
#include "../userVar.h"
#include "../macros.h"

char userNameIn[256];
char userPassIn[256];

// Change user username function
int chngUserName() {
    printf("Enter your password: ");
        GET_INPUT(userPassAtt, sizeof(userPassAtt));

        if (strcmp(userPassAtt, userPass) == 0) {
            printf("Enter your new username: ");
                GET_INPUT(userNameIn, sizeof(userNameIn));

                strcpy(userName, userNameIn);
                printf("\nUsername change to %s\n", userName);
    }

    return 0;
}

// Change user password function
int chngUserPass() {
    printf("Enter your password: ");
        GET_INPUT(userPassAtt, sizeof(userPassAtt));
    
        if (strcmp(userPassAtt, userPass) == 0) {
            printf("Enter your new Password: ");
                GET_INPUT(userPassIn, sizeof(userPassIn));
            
            strcpy(userPass, userPassIn);
        }

    return 0;
}

// Print all user info function
int userEcho() {
    printf("Enter your password: ");
        GET_INPUT(userPassAtt, sizeof(userPassAtt));
    
            if (strcmp(userPassAtt, userPass) == 0) {
                printf("\nUser: %s\n", userName);
                printf("Password: %s\n", userPass);
            }
            
            else {
                return 1;
            }

    return 0;
}