#ifndef AST_H
#define AST_H

#include "lexer.h"
#include "token.h"

//! NOT IMPLEMENTED YET

void ast(lexer_t *lexer);

typedef struct
{
    tkn_t left;
    tkn_t right;
    tkn_t op;
} binary_node_t;

typedef struct
{
    int bruh;
} bruh_t;

#endif /* AST_H */
