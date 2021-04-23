#include "include/lexer.h"
#include "include/utils.h"
#include "include/vec.h"
#include <ctype.h>
#include <string.h>

#define current() (lexer->input->contents[lexer->index])
#define peek() (lexer->input->contents[lexer->index + 1])
#define is_eof() (lexer->index >= lexer->input->length)
#define next() lexer->index++
#define rewind(n) lexer->index -= (n)
#define keyword_match(str)                                                                         \
    (strncmp(lexer->input->contents + lexer->index, str, sizeof(str) - 1) == 0)

// lexer initialization
void lexer_init(lexer_t *lexer, file_t *input)
{
    lexer->output = new_vec(tkn_t);
    lexer->input = input;
    lexer->index = 0;
    lexer->line = 1;
    lexer->col = 1;
}

// free from memory
void lexer_destroy(lexer_t *lexer)
{
    free_vec(lexer->output);
}

// go to next
static inline void lexer_advance(lexer_t *lexer)
{
    if (current() == '\n')
    {
        lexer->col = 1;
        lexer->line++;
    }
    next();
    lexer->col++;
}

// skip whitespace
static void lexer_skip_white(lexer_t *lexer)
{
    while (!is_eof() && isspace(current()))
    {
        lexer_advance(lexer);
    }
}

// Scans ahead to see if we match this string, returning true if we do
static void lexer_tkn(lexer_t *lexer, tkn_type_t type, size_t length)
{
    const tkn_t token =
        tkn_make(pos_make(lexer->line, lexer->col, lexer->input->name),
                 utils_strndup(lexer->input->contents + lexer->index, length), type);
    for (size_t i = 0; i < length; i++)
    {
        lexer_advance(lexer);
    }
    vec_push(lexer->output, token);
}

int lexer_multichar(lexer_t *lexer)
{
    // Only called when first char is start of identifier
    // So we can safely advance
    lexer_advance(lexer);

    // Length of identifier/keyword
    size_t length = 1; // already matched 1 char
    while (!is_eof() && (isalnum(current()) || current() == '_'))
    {
        lexer_advance(lexer);
    }
    rewind(length);
    tkn_type_t type = TknTypeIdentifier;

    if (keyword_match("for"))
        type = TknTypeFor;
    else if (keyword_match("while"))
        type = TknTypeWhile;
    else if (keyword_match("fn"))
        type = TknTypeFunction;
    else if (keyword_match("foreach"))
        type = TknTypeForEach;
    else if (keyword_match("return"))
        type = TknTypeReturn;
    else if (keyword_match("if"))
        type = TknTypeIf;
    else if (keyword_match("import"))
        type = TknTypeImport;
    else if (keyword_match("else"))
        type = TknTypeElse;
    else if (keyword_match("for"))
        type = TknTypeFor;

    return 1;
}

// lexer for single characater
static int lexer_single(lexer_t *lexer)
{
    lexer_skip_white(lexer);
    const char lex_char = current();
    if (isdigit(lex_char))
    {
        size_t i = 1;
        while (isdigit(peek()))
        {
            lexer_advance(lexer);
            i++;
        }
        lexer_tkn(lexer, TknTypeInteger, i);
        return 1;
    }
    switch (lex_char)
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
    case '\n':
        lexer_tkn(lexer, TknTypeNewline, 1);
        break;
    case '+':
        lexer_tkn(lexer, TknTypePLUS, 1);
        break;
    case '-':
        lexer_tkn(lexer, TknTypeMINUS, 1);
        break;
    case '*':
        lexer_tkn(lexer, TknTypeMULTI, 1);
        break;
    case '/':
        lexer_tkn(lexer, TknTypeDIV, 1);
        break;
    case '(':
        lexer_tkn(lexer, TknTypeLeftParen, 1);
        break;
    case ')':
        lexer_tkn(lexer, TknTypeRightParen, 1);
        break;
    case '{':
        lexer_tkn(lexer, TknTypeLeftCurly, 1);
        break;
    case '}':
        lexer_tkn(lexer, TknTypeRightCurly, 1);
        break;
    case '[':
        lexer_tkn(lexer, TknTypeLeftSQRBrackets, 1);
        break;
    case ']':
        lexer_tkn(lexer, TknTypeRightSQRBrackets, 1);
        break;
    default:
        if (lex_char == '_' || isalpha(lex_char))
        {
            return lexer_multichar(lexer);
        }
        else
        {
            return -1;
        }
    }
    return 1;
}

// free tokens
void tokens_free(vec(tkn_t) tkns)
{
    for_each(tkns, tkn_ptr)
    {
        free(tkn_ptr->value);
    }
    free_vec(tkns);
}

// lex the lexer
vec(tkn_t) lexer_lex(lexer_t *lexer)
{
    lexer->index = 0;
    lexer->line = 1;
    lexer->col = 1;
    while (lexer->index < lexer->input->length)
    {
        if (lexer_single(lexer) < 0)
        {
            break;
        }
    }
    return lexer->output;
}
