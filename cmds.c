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
// Read file command variables
char rdFlStr[] = "rd";
char rdFlNm[256];
char buffer[1024];

//----------------//

// Echo function
void echof() {
    printf("> ");
    scanf("%s", userEchoMsg);
    printf("%s\n", userEchoMsg);
}

// OS info function
void osInfof() {
    const char* osInfo = getOS();
    printf("%s\n", osInfo);
}

// Help function
void helpf() {
    printf("\n%s: Command to print text\n", echoStr);
    printf("%s: Command to get info about what OS (Operating System) your currently using\n", osInfoStr);
    printf("%s: Command to see this text\n", helpStr);
    printf("%s: Command to clear the screen\n", clrsStr);
    printf("%s: Command to change username (DEFAULT USERNAME IS 'X' | DEFAULT PASSWORD IS 'VKSHELL')\n", chngUserNameStr);
    printf("%s: Command to change password\n", chngUserPassStr);
    printf("%s: Command to print all user info\n", userEchoStr);
    printf("%s: Command to find the length of a string\n", strLenStr);
    printf("%s: Command to create a file\n", crtFlStr);
    printf("%s: Command to write to a file (add -a to apend content to file | add -a -nl to append content on a newline)\n", wrtFlStr);
    printf("%s: Command to read and print the contents of a file\n", rdFlStr);
    printf("%s: Command to remove a file\n", rmStr);
    printf("%s: Command to exit the VK Shell\n", exitStr);
}

// Clear screen function
void clrsf() {
    printf("\033[2J\033[H");
} 

// Change user username function
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

// Change user password function
void chngUserPass() {
    printf("Enter your password: ");
    scanf(" %[^\n]", userPassAtt);
        if (strcmp(userPassAtt, userPass) == 0) {
            printf("Enter your new Password: ");
            scanf("%s", userPassIn);
            strcpy(userPass, userPassIn);
        }
}

// Print all user info function
void userEcho() {
    printf("Enter your password: ");
    scanf("%s", userPassAtt);
        if (strcmp(userPassAtt, userPass) == 0) {
            printf("\nUser: %s\n", userName);
            printf("Password: %s\n", userPass);
        }
}

// Get string length function
void strLenf() {
    printf("> ");
    scanf(" %[^\n]", strLenUserIn);
        strLen = (strlen(strLenUserIn));
        
        printf("%d", strLen);
}

// Create file function
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

// Remove file function
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

// Write to file function
int wrtFl() {
    // Ask for file to write to
    printf("> ");
    scanf("%s\n> ", wrtFlNm);
    // Ask what content to write to file
    printf("> ");
    fflush(stdout);
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

// Append content to file function (write)
int wrtApFl() {
    // Ask for file to write to
    printf("> ");
    scanf("%s\n> ", wrtFlNm);
    // Ask what content to write to file
    printf("> ");
    fflush(stdout);
    scanf(" %[^\n]", wrtFlInStr);

        FILE *fptr;
        fptr = fopen(wrtFlNm, "a");

        if (fptr == NULL) {
            printf(COLOR_RED "Error: Failed writing to the file %s", wrtFlNm);

            return 1;
        }

            fprintf(fptr, " %s", wrtFlInStr);

                fclose(fptr);

            printf("Writing to file %s was successfull", wrtFlNm);
        
        return 0;
}

// Append content on new line to file function (write)
int wrtFlApNl() {
    // Ask for file to write to
    printf("> ");
    scanf("%s\n> ", wrtFlNm);
    // Ask what content to write to file
    printf("> ");
    fflush(stdout);
    scanf(" %[^\n]", wrtFlInStr);

        FILE *fptr;
        fptr = fopen(wrtFlNm, "a");

        if (fptr == NULL) {
            printf(COLOR_RED "Error: Failed writing to the file %s", wrtFlNm);

            return 1;
        }

            fprintf(fptr, "\n%s", wrtFlInStr);

                fclose(fptr);

            printf("Writing to file %s was successfull", wrtFlNm);
        
        return 0;
}

// Read file function
int rdFl() {
    // Ask for what file to read
    printf("> ");
    scanf("%s", rdFlNm);

    FILE *fptr;
    fptr = fopen(rdFlNm, "r");

    if (fptr == NULL) {
        printf(COLOR_RED "Error: Failed reading file %s", wrtFlNm);

        return 1;
    }

    while (fgets(buffer, sizeof(buffer), fptr) != NULL) {
        printf("\n%s", buffer);
    }

    fclose(fptr);

    return 0;

}

// Exit function
void exitf() {
    printf("Exiting VK Shell...\n");
    exit(0);
}