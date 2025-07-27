#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_io.h"
#include "../userVar.h"
#include "../ansi.h"


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

    wrtFlInStr[strcspn(wrtFlInStr, "\n")] = 0;

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

    wrtFlInStr[strcspn(wrtFlInStr, "\n")] = 0;

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

    wrtFlInStr[strcspn(wrtFlInStr, "\n")] = 0;

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

    printf("\n");

    fclose(fptr);

    return 0;

}