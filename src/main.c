#include "include/ast.h"
#include "include/file.h"
#include "include/lexer.h"
#include "include/vec.h"
#include <stdlib.h>

int main(int argc, char *argv[])
{
    file_t *file = file_read(argc > 1 ? argv[1] : "main.vr");
    if (!file) return EXIT_FAILURE;

    lexer_t lexer;
    lexer_init(&lexer, file);

    if (lexer_lex(&lexer) != EXIT_SUCCESS)
    {
        free(file);
        free(lexer.output);
        return EXIT_SUCCESS;
    }
    for_each(lexer.output, tkn_ptr)
    {
        tkn_dump(tkn_ptr);
    }

    tokens_free(lexer.output);
    free(file);
    return EXIT_SUCCESS;
}
