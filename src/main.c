#include "include/file.h"
#include "include/lexer.h"
#include "include/token.h"

int main(void)
{
    file_t *file = file_read("test.vr");
    if (!file)
        return 1;

    lexer_t lexer;
    lexer_init(&lexer, file);

    vec(tkn_t) tokens = lexer_lex(&lexer);
    for_each(tokens, tkn_ptr)
    {
        tkn_dump(tkn_ptr);
    }

    //lexer_destroy(&lexer);
    tokens_free(tokens);
    free(file);
}
