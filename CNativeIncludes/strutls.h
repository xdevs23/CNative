#ifndef _STRUTLS_H_
#define _STRUTLS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errs.h"

#ifndef MAIN_CMD_MAX_SIZE
#define MAIN_CMD_MAX_SIZE 2048
#endif

/**
 * Convert a string to lower case
 */
static char* string_tolower(char *str) {
    for (int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
    return str;
}

/**
 * Check if string has appended new line, and replace it accordingly by a
 * string terminator
 */
static char* string_checkinput_newline(char *input) {
    if ((strlen(input) > 0) && (input[strlen(input) - 1] == '\n'))
        input[strlen(input) - 1] = '\0';
    return input;
}

/**
 * Check if the size of @param src is bigger or equal to @param cmp
 */
static int string_checksize(char *src, char *cmp) {
    return strlen(src) >= cmp;
}

/**
 * Check if the size of @param src is bigger or equal to MAIN_CMD_MAX_SIZE
 */
static int string_checkmaxsz(char *src) {
    return strlen(src) >= MAIN_CMD_MAX_SIZE;
}

#endif // _STRUTLS_H_
