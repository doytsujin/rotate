#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    const char *name;
    size_t length;
    char contents[];
} file_t;

// Reads a file with the given name and returns an object to later be freed
file_t *file_read(const char *name);

#endif /* FILE_H */