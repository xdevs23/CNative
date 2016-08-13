#include <stdio.h>
#include <stdlib.h>

#include "welcmsg.h"    // Welcome message header
#include "prntutls.h"   // Print utils
#include "cli/cli.h"    // Command Line Interpreter

/**
 * Main entry point
 */
int main() {
    cnative_print_welcome_message();

    char *cmd = malloc(sizeof(cmd)); // Allocate memory for cmd, avoid segfault
    // Loop if not exit or quit
    while(strcmp(cmd, "exit") && strcmp(cmd, "quit")) {
        printf(" > ");
        char *tempcmd = malloc(sizeof(tempcmd));
        scanf("%s", tempcmd);
        strcpy(cmd, tempcmd);
        cli_handle_command(cmd);
    }
    return 0;
}
