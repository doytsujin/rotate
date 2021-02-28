#include "include/lexer.h"
#include "include/utils.h"
#include <ctype.h>
#include <stdbool.h>

#define current() (lexer->input->contents[lexer->index])
#define peek() (lexer->input.contents[lexer->index + 1])
#define is_eof() (lexer->index >= lexer->input->length)
#define next() lexer->index++
#define match(str) lexer_match(lexer, str)
#define rewind(n) lexer->index -= (n)

void lexer_init(lexer_t *lexer, file_t *input)
{
    lexer->output = new_vec(tkn_t);
    lexer->input = input;
    lexer->index = 0;
    lexer->line = 1;
    lexer->col = 1;
}

void lexer_destroy(lexer_t *lexer)
{
    // nothing for now
}

static inline void lexer_advance(lexer_t *lexer)
{
    if (current() == '\n')
    {
        lexer->col = 1;
        lexer->line++;
    }
    next();
}

static void lexer_skip_white(lexer_t *lexer)
{
    while (!is_eof() && isspace(current()))
    {
        lexer_advance(lexer);
    }
}
// Scans ahead to see if we match this string, returning true if we do
static bool lexer_match(lexer_t *lexer, const char *str)
{
    size_t counter = 0;
    while (!is_eof() && current() == *str++)
    {
        next();
        counter++;
    }
    if (*str != 0)
    {
        lexer->index -= counter;
        return false;
    }
    return true;
}

static void lexer_tkn(lexer_t *lexer, tkn_type_t type, size_t length)
{
    const tkn_t token = tkn_make(pos_make(lexer->line, lexer->col, lexer->input->name), utils_strndup(lexer->input->contents + lexer->index, length), type);
    lexer->index += length;
    vec_push(lexer->output, token);
}

static void lexer_single(lexer_t *lexer)
{
    switch (current())
    {
    case '=':
        lexer_tkn(lexer, TknTypeAssign, 1);
        break;
    case ':':
        lexer_tkn(lexer, TknTypeColon, 1);
        break;
    case ';':
        lexer_tkn(lexer, TknTypeSemiColon, 1);
        break;
    case 'f':
    {
        if (match("fn"))
        {
            rewind(2);
            lexer_tkn(lexer, TknTypeFunction, 2);
        }
        break;
    }
    case 'i':
    {
        if (match("import"))
        {
            rewind(6);
            lexer_tkn(lexer, TknTypeImport, 6);
        }
        break;
    }
    default:
        next();
    }
}

void tokens_free(vec(tkn_t) tkns)
{
    for_each(tkns, tkn_ptr)
    {
        free(tkn_ptr->value);
    }
    vec_free(tkns);
}