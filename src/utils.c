#include "include/utils.h"
#include <stdlib.h>
#include <string.h>

char *util_strndup(const char *start, size_t length)
{
    char *buffer = malloc(length + 1);
    memcpy(buffer, start, length);
    buffer[length] = 0;
    return buffer;
}