#ifndef _PRNTUTLS_H_
#define _PRNTUTLS_H_

#include "errs.h"

static void printn(char *msg) {
    printf("%s\n", msg);
}

static int8_t nomemory() {
    cnative_err_no_memory();
    return 1;
}


#endif // _PRNTUTLS_H_
