#include <stdio.h>
#include <string.h>
#include "user.h"
#include "../userVar.h"

char userNameIn[256];
char userPassIn[256];

// Change user username function
int chngUserName() {
    printf("Enter your password: ");
    if (fgets(userPassAtt, sizeof(userPassAtt), stdin) == NULL) {
        printf("Error reading password.\n");
        return 1;
    }

        userPassAtt[strcspn(userPassAtt, "\n")] = 0;

        if (strcmp(userPassAtt, userPass) == 0) {
            printf("Enter your new username: ");
            if (fgets(userNameIn, sizeof(userNameIn), stdin) == NULL) {
                printf("Error reading input\n");
                return 1;
            }

            userNameIn[strcspn(userNameIn, "\n")] = 0;

                strcpy(userName, userNameIn);
                printf("\nUsername change to %s\n", userName);
    }

    return 0;
}

// Change user password function
int chngUserPass() {
    printf("Enter your password: ");
    if (fgets(userPassAtt, sizeof(userPassAtt), stdin) == NULL) {
        printf("Error reading input\n");
        
        return 1;
    }

    userPassAtt[strcspn(userPassAtt, "\n")] = 0;
    
        if (strcmp(userPassAtt, userPass) == 0) {
            printf("Enter your new Password: ");
            if (fgets(userPassIn, sizeof(userPassIn), stdin) == NULL) {
                printf("Error reading failed\n");
                return 1;
            }

            userPassIn[strcspn(userPassIn, "\n")] = 0;
            
            strcpy(userPass, userPassIn);
        }

    return 0;
}

// Print all user info function
int userEcho() {
    if (fgets(userPassAtt, sizeof(userPassAtt), stdin) == NULL) {
        printf("Error reading input\n");
        return 1;
    }

    userPassAtt[strcspn(userPassAtt, "\n")] = 0;
    
        if (strcmp(userPassAtt, userPass) == 0) {
            printf("\nUser: %s\n", userName);
            printf("Password: %s\n", userPass);
        }

    return 0;
}