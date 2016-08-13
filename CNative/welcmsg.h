#ifndef _WELCMSG_H_
#define _WELCMSG_H_

#include "welcome.h"

/// The welcome message to print
static char welcome_message[] = {

    "CNative\n"
    "Command line interpreter application\n"
    "\n"
    "Copyright (C) 2016 Simao Gomes Viana\n"
    "This program is licensed under the Apache License 2.0.\n"
    "This program comes with absolutely no warranty.\n"
    "\n"
    "\n"

};

/**
 * Print the welcome message
 */
static void cnative_print_welcome_message() {
    print_welcome(welcome_message);
}

#endif // _WELCMSG_H_
