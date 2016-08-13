#include <stdio.h>
#include <stdlib.h>

#include "welcmsg.h"

/**
 * Main entry point
 */
int main() {
    cnative_print_welcome_message();
    getchar();  // Just block and wait for ENTER
    return 0;
}
