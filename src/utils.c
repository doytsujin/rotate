#include "include/utils.h"

char *utils_strndup(const char *start, size_t length)
{
    size_t _length = length ? length : 0;
    char *buffer = malloc(_length + 1);
    memcpy(buffer, start ? start : 0, _length);
    buffer[_length] = 0;
    return buffer;
}
