#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "userVar.h"
#include "cmds.h"
#include "os_detect.h"
#include "ansi.h"

int main_sce(void);

int main() {

    printf("\033[2J\033[H");

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
    {"crt", crtFlf},
    {"wrt", wrtFl},
    {"wrt -a", wrtApFl},
    {"wrt -a -nl", wrtFlApNl},
    {"rd", rdFl},
    {"rm", rmf},
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