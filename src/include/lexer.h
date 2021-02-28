#ifndef LEXER_H
#define LEXER_H

#include "token.h"
#include "vec.h"
#include "file.h"
// Defines a vector type of tokens
decl_vec(tkn_t);

typedef struct
{
    file_t *input;
    vec(tkn_t) output;
    size_t index, line, col;
} lexer_t;

void lexer_init(lexer_t *lexer, file_t *input);
void lexer_destroy(lexer_t *lexer);

vec(tkn_t) lexer_lex(lexer_t *lexer);

#endif