#ifndef _EXECUTLS_H_I
#define _EXECUTLS_H_I

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> /* for fork */
#include <sys/types.h> /* for pid_t */
#include <sys/wait.h> /* for wait */

static int executls_execute_program(char *progpath, char *args) {
    char *fullquery = malloc(sizeof(fullquery));
    strcpy(fullquery, progpath);
    strcat(fullquery, " ");
    strcat(fullquery, args);

    // TODO: do not use system() - SECURITY!
    return system(fullquery);
    /*
    int result = 0;
    pid_t pid = fork();
    if (!pid) {
        execv(progpath, args);
        result = 1;
        exit(127); // only if execv fails
    } else {
        waitpid(pid, 0, 0); // wait for child to exit
    }
    return result; */
}

#endif // _EXECUTLS_H_I
