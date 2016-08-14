#ifndef _PRNTUTLS_H_
#define _PRNTUTLS_H_

#include "errs.h"

/**
 * Print a string and append a new line
 */
static void printn(char *msg) {
    printf("%s\n", msg);
}

/**
 * Show an error for no memory (redirects to cnative_err_no_memory and
 * returns 1
 */
static int8_t nomemory() {
    cnative_err_no_memory();
    return 1;
}

#endif // _PRNTUTLS_H_
