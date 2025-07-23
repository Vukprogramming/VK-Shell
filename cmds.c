#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cmds.h"
#include "userVar.h"
#include "os_detect.h"
#include "arithmetic.h"
#include "ansi.h"

//-BASIC VARIABLES-//

// Echo command variables
char echoStr[] = "echo";
char userEchoMsg[512];
// OS info command variables
char osInfoStr[] = "get/osInfo";
char osInfo[32];
// Help command variable
char helpStr[] = "help";
// Clear screen variable
char clrsStr[] = "clrs";
// User password attempt
char userPassAtt[256];
// String length command variables
char strLenStr[] = "strlen";
char strLenUserIn[256];
int strLen;
// Exit command variable
char exitStr[] = "exit";

//-----------------//

//-USER ACCOUNT VARIABLES-//

// Change user username variables
char chngUserNameStr[] = "username -c";
char userNameIn[256];
// Change user password variables
char chngUserPassStr[] = "password -c";
char userPassIn[256];
// Echo all user information
char userEchoStr[] = "echo aui";

//------------------------//

//-FILE VARIABLES-//

// Create file command variables
char crtFlStr[] = "crt";
char crtFlUserIn[256];
// Remove file command variables
char rmStr[] = "rm";
char rmFile[256];
// Write to file command variables
char wrtFlStr[] = "wrt";
char wrtFlApStr[] = "wrt -a";
char wrtFlApNlStr[] = "wrt -a -nl";
char wrtFlNm[256];
char wrtFlInStr[1024];
char wrtFlApInStr[1024];

//----------------//

void echof() {
    printf("> ");
    scanf("%s", userEchoMsg);
    printf("%s\n", userEchoMsg);
}

void osInfof() {
    const char* osInfo = getOS();
    printf("%s\n", osInfo);
}

void helpf() {
    printf("\n%s: Command to print text\n", echoStr);
    printf("%s: Command to get info about what OS (Operating System) your currently using\n", osInfoStr);
    printf("%s: Command to see this text\n", helpStr);
    printf("%s: Command to clear the screen\n", clrsStr);
    printf("%s: Command to change username (DEFAULT USERNAME IS 'X' | DEFAULT PASSWORD IS 'VKSHELL')\n", chngUserNameStr);
    printf("%s: Command to change password\n", chngUserPassStr);
    printf("%s: Command to print all user info\n", userEchoStr);
    printf("%s: Command to remove a file\n", rmStr);
    printf("%s: Command to exit the VK Shell\n", exitStr);
}

void clrsf() {
    printf("\033[2J\033[H");
} 

void chngUserName() {
    printf("Enter your password: ");
    scanf(" %[^\n]", userPassAtt);
        if (strcmp(userPassAtt, userPass) == 0) {
            printf("Enter your new username: ");
            scanf("%s", userNameIn);
                strcpy(userName, userNameIn);
                printf("\nUsername change to %s\n", userName);
    }
}

void chngUserPass() {
    printf("Enter your password: ");
    scanf(" %[^\n]", userPassAtt);
        if (strcmp(userPassAtt, userPass) == 0) {
            printf("Enter your new Password: ");
            scanf("%s", userPassIn);
            strcpy(userPass, userPassIn);
        }
}

void userEcho() {
    printf("Enter your password: ");
    scanf("%s", userPassAtt);
        if (strcmp(userPassAtt, userPass) == 0) {
            printf("\nUser: %s\n", userName);
            printf("Password: %s\n", userPass);
        }
}

void strLenf() {
    printf("> ");
    scanf(" %[^\n]", strLenUserIn);
        strLen = (strlen(strLenUserIn));
        
        printf("%d", strLen);
}

int crtFlf() {
    printf("> ");
    scanf("%s", crtFlUserIn);

        FILE *fptr;
        fptr = fopen(crtFlUserIn, "w");

    if (fptr == NULL) {
        printf("Error: Could not create/open file\n");

        return 1;
    }

        fclose(fptr);  

        printf("File %s has been created and written successfully", crtFlUserIn);

    return 0;
}

void rmf(char *rmFile) {
    printf("Enter your password: ");
    scanf("%s", userPassAtt);
        if (strcmp(userPassAtt, userPass) == 0) {
            printf("> ");
            scanf("%s", rmFile);
    }

    if (rmFile == NULL) {
        printf(COLOR_RED "Error: No filename provided.\n" ANSI_RESET);
        return;
    }

    if (remove(rmFile) == 0) {
        printf("File \"%s\" has been successfully removed.\n", rmFile);
    } else {
        perror(COLOR_RED "Error removing file");
        printf(COLOR_RED ANSI_RESET);
    }
}

int wrtFl() {
    // Ask for file to write to
    printf("> ");
    scanf("%s\n> ", wrtFlNm);
    // Ask what content to write to file
    printf(" ");
    scanf(" %[^\n]", wrtFlInStr);

        FILE *fptr;
        fptr = fopen(wrtFlNm, "w");

        if (fptr == NULL) {
            printf(COLOR_RED "Error: Failed writing to the file %s", wrtFlNm);

            return 1;
        }

            fprintf(fptr, "%s", wrtFlInStr);

                fclose(fptr);

            printf("Writing to file %s was successfull", wrtFlNm);
        
        return 0;
}

void exitf() {
    printf("Exiting VK Shell...\n");
    exit(0);
}