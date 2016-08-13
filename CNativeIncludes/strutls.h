#ifndef _STRUTLS_H_
#define _STRUTLS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char* string_tolower(char *str) {
    for (int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
    return str;
}

static char* string_checkinput_newline(char *input) {
    if ((strlen(input) > 0) && (input[strlen(input) - 1] == '\n'))
        input[strlen(input) - 1] = '\0';
    return input;
}

#endif // _STRUTLS_H_
