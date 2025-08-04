#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "cmds.h"
#include "os_detect.h"
#include "../userVar.h"
#include "../ansi.h"
#include "../macros.h"
#include "../errors.h"
#include "../file_cmds/file_io.h"

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
        GET_INPUT(userEchoMsg, sizeof(userEchoMsg));

    if (strlen(userEchoMsg) == 0) {
        printf(COLOR_RED "%s: %s\n", ERRORS.no_input_entered, ANSI_RESET);
        
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
    printf("time: Tells the current time and date\n");
    printf("vk --ver: Tells basic info about VK shell\n");
    printf("info: Tells info about VK Shell\n");
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
    printf("mkdir: Command to make a directory\n");
    printf("rmdir: Command to remove an empty directory\n");
    printf("exit: Command to exit the VK Shell\n");

    return 0;
}

// Clear screen function
int clrsf() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif

    return 0;
} 

// Get string length function
int strLenf() {
    printf(">");
        GET_INPUT(strLenUserIn , sizeof(strLenUserIn));

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
    printf("VK Shell [Version 1.6.0]\n");

    return 0;
}

int shellDetInfo() {
   rdHcFl("info_d.txt");
    return 0;
}

int getTime() {
    time_t currentTime;
    time(&currentTime);

    printf("%s", ctime(&currentTime));
    return 0;
}
// Exit function
int exitf() {
    printf("Exiting VK Shell...\n");
    exit(0);
    return 0;
}