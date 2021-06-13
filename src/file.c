#include "include/file.h"


file_t *file_read(const char *name)
{
    // open file
    FILE *file = fopen(name, "rb");
    if (!file)
    {
        perror("file open error");
        return NULL;
    }

    // Calculate the file length
    fseek(file, 0, SEEK_END);
    if (!ftell(file))
    {
        fclose(file);
        return NULL;
    }
    const size_t length = ftell(file) ? ftell(file) : 0;

    // c: Rewind to the beginning of STREAM. This function is a possible cancellation point and
    // therefore not marked with __THROW.
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
