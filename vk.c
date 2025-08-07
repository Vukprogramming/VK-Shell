#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "src/userVar.h"
#include "src/basic_cmds/cmds.h"
#include "src/basic_cmds/os_detect.h"
#include "src/ansi.h"
#include "src/file_cmds/file_io.h"
#include "src/calc_cmds/calc.h"
#include "src/user_cmds/user.h"
int main_sce(void);

int main() {

    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    //char userName[256];
    //char userPass[256];

    printf("--------\n");
    printf("VK Shell\n");
    printf("--------\n\n");

    main_sce();

    return 0;
}

    typedef int (*cmd_func_t)(void);

    typedef struct {
        const char *name;
        cmd_func_t func;
    }command_t;

command_t commands[] = {
    {"echo", echof},
    {"get/osInfo", osInfof},
    {"help", helpf},
    {"clrs", clrsf},
    {"chuser", chngUserName},
    {"chpass", chngUserPass},
    {"echo aui", userEcho},
    {"strlen", strLenf},
    {"colors", shwClrTbl},
    {"vk --ver", shellInfo},
    {"info", shellDetInfo},
    {"time", getTime},
    {"add", addf},
    {"sub", subf},
    {"mul", mulf},
    {"div", divf},
    {"crt", crtFlf},
    {"wrt", wrtFl},
    {"wrt -a", wrtApFl},
    {"wrt -a -nl", wrtFlApNl},
    {"rd", rdFl},
    {"rm", rmf},
    {"mkdir", mkDir},
    {"rmdir", rmDir},
    {"exit", exitf},
    {NULL, NULL}
};

int execute_command(const char *userIn) {
    for (int i = 0; commands[i].name != NULL; i++) {
        if (strcmp(userIn, commands[i].name) == 0) {
            return commands[i].func();  // return the result of the command
        }
    }
    printf("Unknown command: %s\n", userIn);
    
    return 0;
}

int main_sce() {
    int should_exit = 0;

    while (!should_exit) {
        printf("%s/> ", userName);
        if (fgets(userIn, sizeof(userIn), stdin) == NULL) {
            break;
        }
        userIn[strcspn(userIn, "\n")] = 0;

        should_exit = execute_command(userIn);  // 1 = exit, 0 = keep going
    }

    return 0;
}