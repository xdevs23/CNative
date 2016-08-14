#ifndef _APPCONFIG_H_
#define _APPCONFIG_H_

/// Version info for CNative
static struct cnative_version_info {
    int16_t major;
    int16_t minor;
    int16_t rev;
};

/// CNative version
struct cnative_version_info cnative_version = { 1, 0, 0 };

#endif // _APPCONFIG_H_
