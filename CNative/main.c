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
    if(cmd == NULL) return nomemory();

    // Loop if not exit or quit
    while(strcasecmp(cmd, "exit") && strcasecmp(cmd, "quit")) {
        printf(" > ");

        char *tempcmd = malloc(MAIN_CMD_MAX_SIZE);
        if(tempcmd == NULL) return nomemory();

        fgets(tempcmd, MAIN_CMD_MAX_SIZE, stdin);

        // Remove trailing newline, if there.
        strcpy(tempcmd, string_checkinput_newline(tempcmd));

        strcpy(cmd, tempcmd);
        cli_handle_command(cmd);
    }

    return 0;
}
