#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cmds.h"
#include "userVar.h"
#include "os_detect.h"
#include "ansi.h"

//-BASIC VARIABLES-//

// Echo command variables
char userEchoMsg[512];
// OS info command variables
char osInfo[32];
// User password attempt
char userPassAtt[256];
// String length command variables
char strLenUserIn[256];
int strLen;

//-----------------//

//-USER ACCOUNT VARIABLES-//

// Change user username variables
char userNameIn[256];
// Change user password variables
char userPassIn[256];

//------------------------//

//-FILE VARIABLES-//

// Create file command variables
char crtFlUserIn[256];
// Remove file command variables
char rmFile[256];
// Write to file command variables
char wrtFlNm[256];
char wrtFlInStr[1024];
// Read file command variables
char rdFlNm[256];
char buffer[1024];

//----------------//

// BASIC COMMAND STRINGS
char echoStr[] = "echo";
char osInfoStr[] = "get/osInfo";
char helpStr[] = "help";
char clrsStr[] = "clrs";
char strLenStr[] = "strlen";
char exitStr[] = "exit";

// USER ACCOUNT COMMAND STRINGS
char chngUserNameStr[] = "chuser";
char chngUserPassStr[] = "chpass";
char userEchoStr[] = "userinfo";

// FILE COMMAND STRINGS
char crtFlStr[] = "create";
char rmStr[] = "rm";
char wrtFlStr[] = "write";
char wrtFlApStr[] = "write -a";
char wrtFlApNlStr[] = "write -a -nl";
char rdFlStr[] = "read";

// Echo function
int echof() {
    printf(">");
    if (fgets(userEchoMsg, sizeof(userEchoMsg), stdin) == NULL) {
        printf("Error: Failed to read input");
        return 1;
    }

    userIn[strcspn(userEchoMsg, "\n")] = 0;  // remove newline

    if (strlen(userEchoMsg) == 0) {
        printf("Error: No user input given");
        
        return 0;
    }

    printf("%s\n", userEchoMsg);

    return 0;
}

// OS info function
int osInfof() {
    const char* osInfo = getOS();
    printf("%s\n", osInfo);

    return 0;
}

// Help function
int helpf() {
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

    return 0;
}

// Clear screen function
int clrsf() {
    printf("\033[2J\033[H");

    return 0;
} 

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

// Get string length function
int strLenf() {
    printf("> ");
    if (fgets(strLenUserIn , sizeof(strLenUserIn), stdin) ==  NULL) {
        printf("Error reading input\n");
        return 1;
    }

    strLenUserIn[strcspn(strLenUserIn, "\n")] = 0;

        strLen = (strlen(strLenUserIn));
        
        printf("%d", strLen);
    
    return 0;
}

// Create file function
int crtFlf() {
    printf("> ");
    if (fgets(crtFlUserIn, sizeof(crtFlUserIn), stdin) == NULL) {
        printf("Error reading input\n");
        return 1;
    }

    crtFlUserIn[strcspn(crtFlUserIn, "\n")] = 0;

        FILE *fptr;
        fptr = fopen(crtFlUserIn, "w");

    if (fptr == NULL) {
        printf("Error: Could not create/open file\n");

        return 1;
    }

        fclose(fptr);  

        printf("File %s has been created and written successfully\n", crtFlUserIn);

    return 0;
}

// Remove file function
int rmf(void) {
    printf("Enter your password: ");
    if (fgets(userPassAtt, sizeof(userPassAtt), stdin) ==  NULL) {
        printf("Error reading input");
        return 1;
    }

    userPassAtt[strcspn(userPassAtt, "\n")] = 0;

        if (strcmp(userPassAtt, userPass) == 0) {
            printf("> ");
            if (fgets(rmFile, sizeof(rmFile), stdin) ==  NULL) {
                printf("Error reading input\n");
                return 1;
            }
    }

    rmFile[strcspn(rmFile, "\n")] = 0;

    if (remove(rmFile) == 0) {
        printf("File \"%s\" has been successfully removed.\n", rmFile);
    } else {
        perror(COLOR_RED "Error removing file\n");
        printf(COLOR_RED ANSI_RESET);
    }

    return 0;
}

// Write to file function
int wrtFl() {
    // Ask for file to write to
    printf("> ");
    if (fgets(wrtFlNm, sizeof(wrtFlNm), stdin) == NULL) {
        printf("Error reading input\n");
        return 1;
    }

    wrtFlNm[strcspn(wrtFlNm, "\n")] = 0;

    // Ask what content to write to file
    printf("> ");
    if (fgets(wrtFlInStr, sizeof(wrtFlInStr), stdin) == NULL) {
        printf("Error reading input\n");
        return 1;
    }

        FILE *fptr;
        fptr = fopen(wrtFlNm, "w");

        if (fptr == NULL) {
            printf(COLOR_RED "Error: Failed writing to the file %s\n", wrtFlNm);

            return 1;
        }

            fprintf(fptr, "%s", wrtFlInStr);

                fclose(fptr);

            printf("Writing to file %s was successfull\n", wrtFlNm);
        
        return 0;
}

// Append content to file function (write)
int wrtApFl() {
    // Ask for file to write to
    printf("> ");
    if (fgets(wrtFlNm, sizeof(wrtFlNm), stdin) == NULL) {
        printf("Error reading input\n");
        return 1;
    }

    wrtFlNm[strcspn(wrtFlNm, "\n")] = 0;

    // Ask what content to write to file
    printf("> ");
    if (fgets(wrtFlInStr, sizeof(wrtFlInStr), stdin) == NULL) {
        printf("Error reading input\n");
        return 1;
    }

        FILE *fptr;
        fptr = fopen(wrtFlNm, "a");

        if (fptr == NULL) {
            printf(COLOR_RED "Error: Failed writing to the file %s\n", wrtFlNm);

            return 1;
        }

            fprintf(fptr, " %s", wrtFlInStr);

                fclose(fptr);

            printf("Writing to file %s was successfull\n", wrtFlNm);
        
        return 0;
}

// Append content on new line to file function (write)
int wrtFlApNl() {
    // Ask for file to write to
    printf("> ");
    if (fgets(wrtFlNm, sizeof(wrtFlNm), stdin) == NULL) {
        printf("Error reading input\n");
        return 1;
    }

    wrtFlNm[strcspn(wrtFlNm, "\n")] = 0;

    // Ask what content to write to file
    printf("> ");
    if (fgets(wrtFlInStr, sizeof(wrtFlInStr), stdin) == NULL) {
        printf("Error reading input\n");
        return 1;
    }

        FILE *fptr;
        fptr = fopen(wrtFlNm, "a");

        if (fptr == NULL) {
            printf(COLOR_RED "Error: Failed writing to the file %s\n", wrtFlNm);

            return 1;
        }

            fprintf(fptr, "\n%s", wrtFlInStr);

                fclose(fptr);

            printf("Writing to file %s was successfull\n", wrtFlNm);
        
        return 0;
}

// Read file function
int rdFl() {
    // Ask for what file to read
    printf("> ");
    if (fgets(rdFlNm, sizeof(rdFlNm), stdin) ==  NULL) {
        printf("Error reading input\n");
        return 1;
    }

    rdFlNm[strcspn(rdFlNm, "\n")] = 0;

    FILE *fptr;
    fptr = fopen(rdFlNm, "r");

    if (fptr == NULL) {
        printf(COLOR_RED "Error: Failed reading file %s\n", wrtFlNm);

        return 1;
    }

    while (fgets(buffer, sizeof(buffer), fptr) != NULL) {
        printf("%s", buffer);
    }

    fclose(fptr);

    return 0;

}

// Exit function
int exitf() {
    printf("Exiting VK Shell...\n");
    exit(0);
    return 0;
}