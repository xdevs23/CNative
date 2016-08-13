#ifndef _DEBUG_H_
#define _DEBUG_H_

#ifdef __DEBUG_ENABLE // Just for debugging in Code::Blocks
static int DEBUG = 1;
#else
static int DEBUG = 0;
#endif

/**
 * Print a debug message with newline if debug is enabled
 * @param msg: The message to print
 **/
static void debugf(char *msg) {
    if(DEBUG) printf("%s\n", msg);
}

#endif // _DEBUG_H_
