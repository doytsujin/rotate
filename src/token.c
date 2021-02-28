#include "include/token.h"

#include <stdio.h>

const char *tkn_type_describe(tkn_type_t type)
{
    switch (type)
    {
    case TokenTypeIdentifier:
        return "id";
        break;
    case TokenTypeAssign:
        return "assign";
        break;
    case TokenTypeNumber:
        return "num";
        break;
    case TokenTypeNewline:
        return "newline";
    default:
        return "???";
        break;
    }
}
void tkn_dump(tkn_t *tkn)
{
    fprintf(stderr, "Token '%s' at %s:%zu:%zu with text \"%s\"\n",
            tkn_type_describe(tkn->type), tkn->pos->file, tkn->pos->line,
            tkn->pos->col, tkn->value);
}
