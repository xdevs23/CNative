#ifndef _CLI_H_
#define _CLI_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cmd_ver.h"
#include "debug.h"
#include "strutls.h"
#include "executls.h"
#include "prntutls.h"
#include "errs.h"

#ifndef MAIN_CMD_MAX_SIZE
#define MAIN_CMD_MAX_SIZE 2048
#endif

/**
 * Hash a command or any string to a number
 */
int cli_char_hash(unsigned char *str) {
    long hash = 21;
    int c = 0;

    while (c = *str++)
        hash = ((hash << 3) + (hash%2)) + c;

    return hash;
}

/// Command identifiers
/// CLI_CMD_ is the prefix, after it comes the actual command
#define CLI_CMD_VER           19298
#define CLI_CMD_GHASHFCMD 516253844
/// End command identifiers

/**
 * Handle a command which was typed into the console previously
 * @param cmd: The commands
 */
static void cli_handle_command(char *cmd) {

    // First make it lower case
    char *newcmd = malloc(MAIN_CMD_MAX_SIZE);

    if(string_checkmaxsz(cmd)) {
        cnative_err_input_too_big();
        return;
    }
    strncpy(newcmd, string_tolower(cmd), strlen(cmd));

    // Now handle the command
    switch(cli_char_hash(newcmd)) {
        case CLI_CMD_GHASHFCMD:
            printf("Enter command: ");
            char *encmd = malloc(MAIN_CMD_MAX_SIZE);
            fgets(encmd, MAIN_CMD_MAX_SIZE, stdin);

            if(string_checkmaxsz(encmd)) {
                cnative_err_input_too_big();
                break;
            }

            printf("Generating hash for command %s", encmd);
            strncpy(
                encmd,
                string_tolower(string_checkinput_newline(encmd)),
                strlen(encmd)
            );
            printf("\nGenerated hash: %d\n", cli_char_hash(encmd));
            break;
        case CLI_CMD_VER:
            builtin_cmd_ver_oncommand();
            break;
        default:
            if(executls_execute_program(newcmd, ""))
                printf("%s: not found\n", newcmd);
            break;
    }
}


#endif // _CLI_H_
