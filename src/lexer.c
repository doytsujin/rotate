#include "include/lexer.h"
#include "include/utils.h"

#define current() (lexer->input.contents[lexer->index])
#define peek() (lexer->input.contents[lexer->index + 1])

#define is_eof() (lexer->index >= lexer->input.length)

void lexer_init(lexer_t *lexer, file_t *input)
{
    lexer->output = new_vec(tkn_t);
    lexer->input = input;
    lexer->index = 0;
    lexer->line = 1;
    lexer->col = 1;
}

void lexer_destroy(lexer_t *lexer)
{
    // nothing for now
}