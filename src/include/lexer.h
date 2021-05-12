#ifndef LEXER_H
#define LEXER_H

#include "file.h"
#include "token.h"
#include "vec.h"
#include "utils.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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
int lexer_multichar(lexer_t *lexer);
void tokens_free(vec(tkn_t) tkns);
int lexer_lex(lexer_t *lexer);

#endif /* LEXER_H */
