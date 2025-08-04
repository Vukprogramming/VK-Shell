#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "file_io.h"
#include "../userVar.h"
#include "../ansi.h"
#include "../macros.h"
#include "../errors.h"

#ifdef _WIN32
    #include <direct.h> // For _mkdir() and _rmdir()
#else
    #include <sys/stat.h> // For mkdir()
    #include <unistd.h> // For rmdir()
#endif


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
// Hardcoded file
char artFile[256];
// Make directory command variable
char dirName[256];

//----------------//

// Create file function
int crtFlf() {
    printf("File:");
    GET_INPUT(crtFlUserIn, sizeof(crtFlUserIn));

        FILE *fptr;
        fptr = fopen(crtFlUserIn, "w");

    if (fptr == NULL) {
        printf(COLOR_RED "%s: %s" ANSI_RESET "\n", ERRORS.failed_create_file, strerror(errno));

        return 0;
    }

        fclose(fptr);  

        printf("File %s has been created and written successfully\n", crtFlUserIn);

    return 0;
}

// Remove file function
int rmf(void) {
    CHECK_PASS(userPassAtt, sizeof(userPassAtt));

        if (strcmp(userPassAtt, userPass) == 0) {
            printf("File: ");
            if (fgets(rmFile, sizeof(rmFile), stdin) ==  NULL) {
                printf(COLOR_RED "%s: %s" ANSI_RESET "\n", ERRORS.failed_removing_file, strerror(errno));
                return 0;
            }
        }
        else {
            return 1;
        }

    STRIP_NL(rmFile);

    if (remove(rmFile) == 0) {
        printf("File \"%s\" has been successfully removed.\n", rmFile);
    } else {
        printf(COLOR_RED "%s: %s" ANSI_RESET "\n", ERRORS.failed_removing_file, strerror(errno));
    }

    return 0;
}

// Write to file function
int wrtFl() {
    // Ask for file to write to
    printf("File:");
        GET_INPUT(wrtFlNm, sizeof(wrtFlNm));    

    // Ask what content to write to file
    printf("Content:");
        GET_INPUT(wrtFlInStr, sizeof(wrtFlInStr));

        FILE *fptr;
        fptr = fopen(wrtFlNm, "w");

        if (fptr == NULL) {
            printf(COLOR_RED "%s: %s" ANSI_RESET "\n", ERRORS.failed_write_to_file, strerror(errno));

            return 0;
        }

            fprintf(fptr, "%s", wrtFlInStr);

                fclose(fptr);

            printf("Writing to file %s was successfull\n", wrtFlNm);
        
        return 0;
}

// Append content to file function (write)
int wrtApFl() {
    // Ask for file to write to
    printf("File:");
        GET_INPUT(wrtFlNm, sizeof(wrtFlNm));

    // Ask what content to write to file
    printf("Content:");
        GET_INPUT(wrtFlInStr, sizeof(wrtFlInStr));

        FILE *fptr;
        fptr = fopen(wrtFlNm, "a");

        if (fptr == NULL) {
            printf(COLOR_RED "%s: %s" ANSI_RESET "\n", ERRORS.failed_write_to_file, strerror(errno));

            return 0;
        }

            fprintf(fptr, " %s", wrtFlInStr);

                fclose(fptr);

            printf("Writing to file %s was successfull\n", wrtFlNm);
        
        return 0;
}

// Append content on new line to file function (write)
int wrtFlApNl() {
    // Ask for file to write to
    printf("File:");
        GET_INPUT(wrtFlNm, sizeof(wrtFlNm));

    // Ask what content to write to file
    printf("Content:");
        GET_INPUT(wrtFlInStr, sizeof(wrtFlInStr));

        FILE *fptr;
        fptr = fopen(wrtFlNm, "a");

        if (fptr == NULL) {
            printf(COLOR_RED "%s: %s" ANSI_RESET "\n", ERRORS.failed_write_to_file, strerror(errno));

            return 0;
        }

            fprintf(fptr, "\n%s", wrtFlInStr);

                fclose(fptr);

            printf("Writing to file %s was successfull\n", wrtFlNm);
        
        return 0;
}

// Read file function
int rdFl() {
    // Ask for what file to read
    printf("File:");
        GET_INPUT(rdFlNm, sizeof(rdFlNm));

    FILE *fptr; 
    fptr = fopen(rdFlNm, "r");

    if (fptr == NULL) {
        printf(COLOR_RED "%s: %s" ANSI_RESET "\n", ERRORS.failed_to_read_file, strerror(errno));

        return 0;
    }

    while (fgets(buffer, sizeof(buffer), fptr) != NULL) {
        printf("%s", buffer);
    }

    printf("\n");

    fclose(fptr);

    return 0;

}

int rdHcFl(const char* artFile) {
    FILE *fptr;
    fptr = fopen(artFile, "r");

    if (fptr ==  NULL) {
        printf(COLOR_RED "%s: %s" ANSI_RESET "\n", ERRORS.failed_to_read_file, strerror(errno));

        return 0;
    }

    while (fgets(buffer, sizeof(buffer), fptr) != NULL) {
        printf("%s", buffer);
    }

    printf("\n");

    fclose(fptr);

    return 0;
}

int mkDir() {
    printf("Directory:");
        GET_INPUT(dirName, sizeof(dirName));

    #ifdef _WIN32
        if (_mkdir(dirName) == 0) {
            printf("Successfully created directory %s\n", dirName);

            return 0;
        }
        else {
            printf(COLOR_RED "%s: %s" ANSI_RESET "\n", ERRORS.failed_create_directory, strerror(errno));
            
            return 0;
        }

    #else
        if (mkdir(dirName, 0755) == 0) {
            printf("Successfully created directory %s\n", dirName); 
            
            return 0;
        }
        else {
            printf(COLOR_RED "%s: %s" ANSI_RESET "\n", ERRORS.failed_create_directory, strerror(errno));
            
            return 0;
        }
    #endif

    return 0;
}

int rmDir() {
    CHECK_PASS(userPassAtt, sizeof(userPassAtt));

        if (strcmp(userPassAtt, userPass) == 0) {
            printf("Directory:");
                GET_INPUT(dirName, sizeof(dirName));
        #ifdef _WIN32
            if (_rmdir(dirName) == 0) {
                printf("Successfully removed directory %s\n", dirName);

                return 0;
            }
            else {
                printf(COLOR_RED "%s: %s" ANSI_RESET "\n", ERRORS.failed_remove_directory, strerror(errno));

                return 0;
            }
    
        #else
            if (rmdir(dirName) == 0) {
                printf("Successfully removed directory %s\n", dirName);

                return 0;
            }
            else {
                printf(COLOR_RED "%s: %s" ANSI_RESET "\n", ERRORS.failed_remove_directory, strerror(errno));

                return 0;
            }
        #endif
        }
        
        else {
            return 1;
        }

    return 0;
}