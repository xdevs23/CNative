#ifndef _CMD_VER_H_
#define _CMD_VER_H_

#include "prntutls.h"
#include "../CNative/appconfig.h"

static void builtin_cmd_ver_oncommand() {
    printf("CNative %d.%d.%d\n",
        cnative_version.major,
        cnative_version.minor,
        cnative_version.rev);
}


#endif /* _CMD_VER_H_ */
