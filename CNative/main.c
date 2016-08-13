#include <stdio.h>
#include <stdlib.h>

#include "welcmsg.h"    // Welcome message header
#include "prntutls.h"   // Print utils
#include "cli/cli.h"    // Command Line Interpreter

#define MAIN_CMD_MAX_SIZE 2048

/**
 * Main entry point
 */
int main() {
    cnative_print_welcome_message();

    // Allocate memory for cmd, avoid segfault
    char *cmd = malloc(MAIN_CMD_MAX_SIZE);

    // Check for memory
    if(cmd == NULL) goto nomemory;

    // Loop if not exit or quit
    while(strcasecmp(cmd, "exit") && strcasecmp(cmd, "quit")) {
        printf(" > ");
        char *tempcmd = malloc(sizeof(tempcmd));
        if(tempcmd == NULL) goto nomemory
        scanf("%s", tempcmd);
        strcpy(cmd, tempcmd);
        cli_handle_command(cmd);
    }
    return 0;

nomemory:
    printn("Error: Memory not allocatable or no free memory available");
    return 1;
}
