#ifndef _PRNTUTLS_H_
#define _PRNTUTLS_H_


static void printn(char *msg) {
    printf("%s\n", msg);
}

static int8_t nomemory() {
    printn("Error: Memory not allocatable or no free memory available");
    return 1;
}


#endif // _PRNTUTLS_H_
