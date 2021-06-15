#ifndef LEXER_H
#define LEXER_H

#include "file.h"
#include "token.h"
#include "utils.h"
#include "vec.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdint.h>

// types of possible errors
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

// get current char
#define current() (lexer->input->contents[lexer->index])
// get next char
#define peek() (lexer->input->contents[lexer->index + 1])
// get char at specific index
#define specific(i) (lexer->input->contents[lexer->index + i])
// get last char
#define past() (lexer->input->contents[lexer->index - 1])
// check if is end of file
#define is_eof() (lexer->index >= lexer->input->length)
// increment length
#define add_len() (lexer->length++)
// reset length to zero
#define reset_len() (lexer->length = 0)
// get current length
#define length() (lexer->length)
// push to next index
#define next() lexer->index++
// rewind index by number
#define rewind_macro(n) lexer->index -= (n)
// if keyword matches
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

// lexes multicharacters
int lexer_multichar(lexer_t *lexer);

// free tokens from memory
void tokens_free(vec(tkn_t) tkns);

// to lex the lexer
int lexer_lex(lexer_t *lexer);

// display error output
int lexer_lex_failure(lexer_t *lexer);

#endif /* LEXER_H */
