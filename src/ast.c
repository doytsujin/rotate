#include "include/ast.h"

void ast(lexer_t *lexer)
{
    for_each(lexer->output, tkn_t)
    {
        printf("tkn_t->value: %s\n", tkn_t->value);
        printf("tkn_t->type %d\n", tkn_t->type);
        printf("tkn_t->type %s\n", tkn_t->pos.file);
    }
}
