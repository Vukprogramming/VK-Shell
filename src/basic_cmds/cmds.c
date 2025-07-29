#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cmds.h"
#include "os_detect.h"
#include "../userVar.h"
#include "../ansi.h"

//-BASIC VARIABLES-//

// Echo command variables
char userEchoMsg[512];
// OS info command variables
char osInfo[32];
// String length command variables
char strLenUserIn[256];
int strLen;

//-----------------//

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
    printf("\necho: Command to print text\n");
    printf("get/osInfo: Command to get info about what OS (Operating System) your currently using\n");
    printf("help: Command to see this text\n");
    printf("clrs: Command to clear the screen\n");
    printf("strlen: Command to find the length of a string\n");
    printf("colors: Command to print the ANSI color table\n");
    printf("add: Adds two numbers\n");
    printf("sub: Subtracts two numbers\n");
    printf("mul: Multiplies two numbers\n");
    printf("div: Divides two numbers\n");
    printf("chuser: Command to change username (DEFAULT USERNAME IS 'X' | DEFAULT PASSWORD IS 'VKSHELL')\n");
    printf("chpass: Command to change password\n");
    printf("echo aui: Command to print all user info\n");
    printf("crt: Command to create a file\n");
    printf("wrt: Command to write to a file (add -a to apend content to file | add -a -nl to append content on a newline)\n");
    printf("rd: Command to read and print the contents of a file\n");
    printf("rm: Command to remove a file\n");
    printf("exit: Command to exit the VK Shell\n");

    return 0;
}

// Clear screen function
int clrsf() {
    printf("\033[2J\033[H");

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
        
        printf("%d\n", strLen);
    
    return 0;
}

int shwClrTbl()  {
    printf("--ANSI COLOR TABLE--\n\n");
    printf(WHITE_BACKGROUND COLOR_BLACK "BLACK" ANSI_RESET "    " COLOR_BLUE "     BLUE\n");
    printf(COLOR_GREEN "GREEN    " COLOR_CYAN "     CYAN\n");
    printf(COLOR_RED "RED           " COLOR_MAGENTA "MAGENTA\n");
    printf(COLOR_LIGHT_GRAY "LIGHT GRAY    " COLOR_DARK_GRAY "DARK GRAY\n");
    printf(COLOR_LIGHT_BLUE "LIGHT BLUE    " COLOR_LIGHT_GREEN "LIGHT GREEN\n");
    printf(COLOR_LIGHT_CYAN "LIGHT CYAN    " COLOR_LIGHT_RED "LIGHT RED\n");
    printf(COLOR_LIGHT_MAGENTA "      LIGHT MAGENTA\n" ANSI_RESET);

    return 0;
}

int shellInfo() {
    printf("VK Shell [Version 1.5]\n");

    return 0;
}
// Exit function
int exitf() {
    printf("Exiting VK Shell...\n");
    exit(0);
    return 0;
}