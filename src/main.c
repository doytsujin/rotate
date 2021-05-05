#include "include/file.h"
#include "include/lexer.h"
#include "include/token.h"
#include <stdlib.h>

int main(void)
{
    file_t *file = file_read("test.vr");
    if (!file)
        return EXIT_SUCCESS;

    lexer_t lexer;
    lexer_init(&lexer, file);

    if (lexer_lex(&lexer) != EXIT_SUCCESS)
    {
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