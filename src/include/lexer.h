#ifndef LEXER_H
#define LEXER_H

#include "file.h"
#include "token.h"
#include "utils.h"
#include "vec.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum
{
    UNKNOWN,
    CHAR_OVER_ONE,
    NOT_CLOSED_SINGLE_QUOTE,
    NOT_CLOSED_DOUBLE_QUOTE,
    END_OF_FILE,
};

#define current() (lexer->input->contents[lexer->index])
#define peek() (lexer->input->contents[lexer->index + 1])
#define specific(i) (lexer->input->contents[lexer->index + i])
#define past() (lexer->input->contents[lexer->index - 1])
#define is_eof() (lexer->index >= lexer->input->length)
#define add_len() (lexer->length++)
#define reset_len() (lexer->length = 0)
#define length() (lexer->length)
#define next() lexer->index++
#define rewind_macro(n) lexer->index -= (n)
#define keyword_match(str) (strncmp(lexer->input->contents + lexer->index, str, length) == 0)

// Defines a vector type of tokens
decl_vec(tkn_t);

typedef struct
{
    file_t *input;
    vec(tkn_t) output;
    size_t index, line, col;
    size_t length;
    size_t error_type;
} lexer_t;

void lexer_init(lexer_t *lexer, file_t *input);
void lexer_destroy(lexer_t *lexer);
int lexer_multichar(lexer_t *lexer);
void tokens_free(vec(tkn_t) tkns);
int lexer_lex(lexer_t *lexer);
int lexer_lex_failure(lexer_t *lexer);

#endif /* LEXER_H */
