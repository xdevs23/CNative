#ifndef _ERRS_H_
#define _ERRS_H_

/// No memory
static void cnative_err_no_memory() {
    printf("Error: Memory not allocatable or no free memory available.\n");
}

/// Input too big
static void cnative_err_input_too_big() {
    printf("Error: The entered value is too big and cannot be handled.\n");
}

#endif // _ERRS_H_
