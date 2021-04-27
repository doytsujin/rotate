#ifndef LEXER_H
#define LEXER_H

#include "file.h"
#include "token.h"
#include "vec.h"

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
static inline void lexer_advance(lexer_t * lexer);
static void lexer_skip_white(lexer_t *lexer);
static void lexer_tkn(lexer_t *lexer, tkn_type_t type, size_t length);
int lexer_multichar(lexer_t *lexer);
static int lexer_single(lexer_t *lexer);
void tokens_free(vec(tkn_t) tkns);
vec(tkn_t) lexer_lex(lexer_t *lexer);

#endif /* LEXER_H */
