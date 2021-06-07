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

typedef enum
{
    /// Unknown token/error (default)
    UNKNOWN,
    /// Single quote not closed
    NOT_CLOSED_CHAR,
    /// Double quote not closed
    NOT_CLOSED_STRING,
    /// File empty error
    FILE_EMPTY,
    /// End of file error
    END_OF_FILE,
} err_kind;

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
    err_kind error_type;
} lexer_t;

/// init a lexer from a file
void lexer_init(lexer_t *lexer, file_t *input);

// destroy lexer from memory
void lexer_destroy(lexer_t *lexer);

int lexer_multichar(lexer_t *lexer);

// free tokens from memory
void tokens_free(vec(tkn_t) tkns);

int lexer_lex(lexer_t *lexer);

// display error output
int lexer_lex_failure(lexer_t *lexer);

#endif /* LEXER_H */
