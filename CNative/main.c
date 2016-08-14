#include <stdio.h>
#include <stdlib.h>

#include "welcmsg.h"    // Welcome message header
#include "prntutls.h"   // Print utils
#include "cli/cli.h"    // Command Line Interpreter
#include "strutls.h"    // String utils
#include "errs.h"       // Error messages

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
        strncpy(tempcmd, string_checkinput_newline(tempcmd),
            strlen(tempcmd) + 1);

        if(string_checksize(tempcmd, MAIN_CMD_MAX_SIZE)) {
            cnative_err_input_too_big();
            continue;
        }

        strncpy(cmd, tempcmd, strlen(tempcmd) + 1);
        cli_handle_command(cmd);
    }

    return 0;
}
