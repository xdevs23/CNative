#ifndef _CLI_H_
#define _CLI_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cmd_ver.h"
#include "debug.h"

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
    switch(cli_char_hash(cmd)) {
        case CLI_CMD_GHASHFCMD:
            printf("Enter command: ");
            char *encmd = malloc(sizeof(encmd));
            scanf("%s", encmd);
            printf("Generating hash for command %s", encmd);
            for(int i = 0; encmd[i]; i++){
              encmd[i] = tolower(encmd[i]);
            }
            printf("\n%d\n", cli_char_hash(encmd));
            break;
        case CLI_CMD_VER:
            builtin_cmd_ver_oncommand();
            break;
        default: break;
    }
}


#endif // _CLI_H_
