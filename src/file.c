#include "include/prettyerr.h"

file_t *file_read(char *name)
{
    // open file
    FILE *file = fopen(name, "rb");
    if (!file)
    {
        // perror("file open error");
        // display error message if file does not exist
        printf("%s%s%s: %serror:%s %s%s\n", GREEN, BOLD, name, RED, LCYAN,
               "No such file or directory", RESET);
        return NULL;
    }

    // Calculate the file length
    fseek(file, 0, SEEK_END);
    if (!ftell(file))
    {
        printf("%s%s%s: %serror:%s %s%s\n", GREEN, BOLD, name, RED, LCYAN, "File empty", RESET);
        // printf("\x1b[31merror: file empty \x1b[0m\n");
        fclose(file);
        return NULL;
    }
    const size_t length = ftell(file);
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
