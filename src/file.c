#include "include/file.h"
#include <stdio.h>

file_t *file_read(const char *name)
{
    FILE *file = fopen(name, "rb");
    if (!file)
    {
        perror("fopen");
        return NULL;
    }

    // Calculate the file length
    fseek(file, 0, SEEK_END);
    const size_t length = ftell(file);
    if (!ftell(file))
    {
        fclose(file);
        return NULL;
    }
    rewind(file);

    // Read the file into a buffer
    file_t *buffer = malloc(sizeof(file_t) + length + 1);
    buffer->length = length;
    buffer->name = name;
    if (fread(buffer->contents, sizeof(char), length, file) != length)
    {
        perror("ERR: fread err");
        fclose(file);
        free(buffer);
        return NULL;
    }

    buffer->contents[length] = 0;

    // Close the file
    fclose(file);
    return buffer;
}
