#include "include/file.h"
#include "include/token.h"
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
    tkn_t token = tkn_make(pos_make(1, 1, filename),  "x",TknTypeIdentifier);
    tkn_dump(&token); 
}