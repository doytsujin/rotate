#include "include/file.h"

file_t *file_read(const char *name)
{
    FILE *file = fopen(name, "r");
    if (!file)
    {
        perror("fopen");
        return NULL;
    }

    // Calculate the file length
    fseek(file, 0, SEEK_END);
    const size_t length = ftell(file);
    rewind(file);

    // Read the file into a buffer
    file_t *buffer = malloc(sizeof(file_t) + length + 1);
    buffer->length = length;
    buffer->name = name;
    if (fread(buffer->contents, sizeof(char), length, file) != length)
    {
        perror("fread");
        return NULL;
    }
    buffer->contents[length] = 0;

    // Close the file
    fclose(file);

    return buffer;
}
