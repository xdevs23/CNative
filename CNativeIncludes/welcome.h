#ifndef _WELCOME_H_
#define _WELCOME_H_

#include "debug.h"

/**
 * Print a welcome message
 */
static void print_welcome(char *output) {

    debugf("Printing welcome");
    printf("%s\n", output);

}

#endif // _WELCOME_H_
