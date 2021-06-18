#ifndef AST_H
#define AST_H

#include "token.h"

typedef struct ast_t ast_t;
typedef struct scope_ast_t scope_ast_t;

typedef struct scope_ast_t
{
    scope_ast_t *previous;
} scope_ast_t;

typedef struct {
    tkn_t kind;
    scope_ast_t *scope;
} variables_ast_t;


#endif /* AST_H */
