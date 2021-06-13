#include "include/utils.h"

// duplicate source code
char *utils_strndup(const char *start, size_t length)
{
    char *buffer = malloc(length + 1);
    memcpy(buffer, start, length);
    buffer[length] = 0;
    return buffer;
}
