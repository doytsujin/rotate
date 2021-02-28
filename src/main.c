#include "include/file.h"

int main(int argc, char **argv)
{
    char *filename;
    if (argc > 1)
    {
        filename = argv[1];
    }
    else
    {
        filename = "test.vr";
    }

    file_t *file = file_read(filename);
    if (!file)
        return 1;
    puts(file->contents);
    free(file);
}