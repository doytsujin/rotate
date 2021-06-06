#include "include/lexer.h"
#include "include/prettyerr.h"
#include "include/token.h"
#include <stdlib.h>

#define current() (lexer->input->contents[lexer->index])
#define peek() (lexer->input->contents[lexer->index + 1])
#define specific(i) (lexer->input->contents[lexer->index + i])
#define past() (lexer->input->contents[lexer->index - 1])
#define is_eof() (lexer->index >= lexer->input->length)
#define next() lexer->index++
#define rewind(n) lexer->index -= (n)
#define keyword_match(str) (strncmp(lexer->input->contents + lexer->index, str, length) == 0)

// lexer initialization
void lexer_init(lexer_t *lexer, file_t *input)
{
    lexer->output = new_vec(tkn_t);
    lexer->input = input;
    lexer->index = 0;
    lexer->line = 1;
    lexer->col = 1;
    lexer->length = 1;
}

// free from memory
void lexer_destroy(lexer_t *lexer)
{
    free_vec(lexer->output);
}

// go to next
static inline void lexer_advance(lexer_t *lexer)
{
    const char c = current();
    next();
    if (c != '\n')
    {
        lexer->col++;
    }
    else
    {
        lexer->col = 1;
        lexer->line++;
    }
}

// skip whitespace
static void lexer_skip_white(lexer_t *lexer)
{
    while (!is_eof() && isspace(current()))
    {
        lexer_advance(lexer);
    }
}

// Scans ahead to see if we match this string
static void lexer_tkn(lexer_t *lexer, tkn_type_t type, size_t length)
{
    lexer->length = length;
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
    size_t save_index = lexer->index;
    size_t save_line = lexer->line;
    size_t save_col = lexer->col;
    size_t save_length = lexer->length;

    // Only called when first char is start of identifier
    // So we can safely advance
    lexer_advance(lexer);
    // Length of identifier/Typeword
    size_t length = 1; // already matched 1 char
    while (!is_eof() && (isalnum(current()) || current() == '_'))
    {
        lexer_advance(lexer);
        length++;
    }
    save_length = length;
    lexer->index = save_index;
    lexer->line = save_line;
    lexer->col = save_col;
    lexer->length = save_length;
    tkn_type_t type = TknTypeIdentifier;

    if (keyword_match("foreach") && length == 7)
        type = TknTypeForEach;
    else if (keyword_match("as") && length == 2)
        type = TknTypeAs;
    else if (keyword_match("for") && length == 3)
        type = TknTypeFor;
    else if (keyword_match("while") && length == 5)
        type = TknTypeWhile;
    else if (keyword_match("fn") && length == 2)
        type = TknTypeFunction;
    else if (keyword_match("return") && length == 6)
        type = TknTypeReturn;
    else if (keyword_match("if") && length == 2)
        type = TknTypeIf;
    else if (keyword_match("import") && length == 6)
        type = TknTypeImport;
    else if (keyword_match("else") && length == 4)
        type = TknTypeElse;
    else if (keyword_match("for") && length == 3)
        type = TknTypeFor;
    else if (keyword_match("true") && length == 4)
        type = TknTypeTrue;
    else if (keyword_match("false") && length == 5)
        type = TknTypeFalse;
    else if (keyword_match("let") && length == 3)
        type = TknTypeLet;
    else if (keyword_match("pub") && length == 3)
        type = TknTypePublic;
    else if (keyword_match("mut") && length == 3)
        type = TknTypeMutable;
    else if (keyword_match("str") && length == 3)
        type = TknTypeStringType;
    else if (keyword_match("int") && length == 3)
        type = TknTypeIntType;
    else if (keyword_match("float") && length == 6)
        type = TknTypeFloatType;
    else if (keyword_match("char") && length == 4)
        type = TknTypeCharType;
    else if (keyword_match("bool") && length == 4)
        type = TknTypeBoolType;
    else if (keyword_match("match") && length == 5)
        type = TknTypeMatch;
    else if (keyword_match("break") && length == 5)
        type = TknTypeBreak;
    else
    {
        // printf("Error at %c %zu:%zu\n", current(), lexer->line, lexer->col);
        // exit(2);
    }
    lexer_tkn(lexer, type, save_length);
    return EXIT_SUCCESS;
}

// lexer for single characater
static int lexer_single(lexer_t *lexer)
{

    lexer_skip_white(lexer);
    const char lex_char = current();
    lexer->length = 1;
    // digit lexer
    if (isdigit(lex_char))
    {

        size_t save_index = lexer->index;
        size_t save_line = lexer->line;
        size_t save_col = lexer->col;
        size_t i = 1;
        lexer_advance(lexer);
        bool reached_dot = false;
        while (isdigit(current()) || current() == '.')
        {
            if (current() == '.')
            {
                if (reached_dot) break;
                reached_dot = true;
            }
            lexer_advance(lexer);
            i++;
        }
        lexer->index = save_index;
        lexer->line = save_line;
        lexer->col = save_col;
        lexer->length = i;
        lexer_tkn(lexer, reached_dot ? TknTypeFloat : TknTypeInteger, i);
        return EXIT_SUCCESS;
    }

    // string lexer
    else if (lex_char == '"')
    {
        // string lexer
        size_t save_index = lexer->index;
        size_t save_line = lexer->line;
        size_t save_col = lexer->col;
        size_t length = 1;
        lexer_advance(lexer);
        while (!is_eof() && current() != '\"')
        {
            // printf("%c\n", current());
            lexer_advance(lexer);
            length++;
        }
        if (is_eof()) return EXIT_FAILURE;
        length++;
        lexer->index = save_index;
        lexer->line = save_line;
        lexer->col = save_col;
        lexer->length = length;
        lexer_tkn(lexer, TknTypeString, length);
        return EXIT_SUCCESS;
    }
    // char lexer
    else if (lex_char == '\'')
    {
        // char lexer
        size_t save_index = lexer->index;
        size_t save_line = lexer->line;
        size_t save_col = lexer->col;
        size_t length = 1;
        lexer_advance(lexer);
        while (!is_eof() && current() != '\'')
        {
            // printf("%c\n", current());
            lexer_advance(lexer);
            length++;
            if (length > 3) return EXIT_FAILURE;
            if (length == 1 && current() == 10)
            {
                lexer_advance(lexer);
                length++;
                break;
            }
        }
        if (is_eof()) return EXIT_FAILURE;
        length++;
        lexer->index = save_index;
        lexer->line = save_line;
        lexer->col = save_col;
        lexer_tkn(lexer, TknTypeChar, length);
        return EXIT_SUCCESS;
    }

    // lexer for single chars
    switch (lex_char)
    {
        case '_':
            lexer_tkn(lexer, TknTypeDefault, 1);
            break;
        case '|':
            lexer_tkn(lexer, TknTypeDivider, 1);
            break;
        case '=':
            if (peek() == '=')
            {
                lexer_tkn(lexer, TknTypeEqualEqual, 2);
                lexer_advance(lexer);
            }
            else
                lexer_tkn(lexer, TknTypeEqual, 1);
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
            if (peek() == '>')
            {
                lexer_tkn(lexer, TknTypeArrow, 2);
                lexer_advance(lexer);
            }
            else
                lexer_tkn(lexer, TknTypeMINUS, 1);
            break;
        case '*':
            lexer_tkn(lexer, TknTypeStar, 1);
            break;
        case '/':
            if (peek() == '/')
            {
                while (!is_eof() && current() != '\n' && current() != '\0')
                {
                    lexer_advance(lexer);
                }
            }
            else
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
        case '>':
            lexer_tkn(lexer, TknTypeGreater, 1);
            break;
        case '<':
            lexer_tkn(lexer, TknTypeLess, 1);
            break;
        case '.':
            lexer_tkn(lexer, TknTypeDot, 1);
            break;
        case '$':
            lexer_tkn(lexer, TknTypeDollar, 1);
            break;
        case '!':
            lexer_tkn(lexer, TknTypeNot, 1);
            break;
        case '%':
            lexer_tkn(lexer, TknTypeMod, 1);
            break;
        case ',':
            lexer_tkn(lexer, TknTypeComma, 1);
            break;
        default:
            if (lex_char == '_' || isalpha(lex_char))
            {
                return lexer_multichar(lexer);
            }
            else
            {
                return EXIT_FAILURE;
            }
    }
    return EXIT_SUCCESS;
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
int lexer_lex(lexer_t *lexer)
{
    lexer->index = 0;
    lexer->line = 1;
    lexer->col = 1;
    while (!is_eof())
    {
        if (lexer_single(lexer) != EXIT_SUCCESS)
        {
            return lexer_lex_failure(lexer);
        }
        lexer_skip_white(lexer);
    }
    return EXIT_SUCCESS;
}
// failure display
int lexer_lex_failure(lexer_t *lexer)
{
    size_t len = lexer->length;
    char word[len + 1];
    char arrows[len + 1];
    for (size_t i = 0; i < len; i++)
    {
        word[i] = specific(i) != '\n' ? specific(i) : '\0';
        arrows[i] = '-';
    }
    word[len] = 0;
    arrows[len] = 0;

    size_t j = 0;
    while (current() != '\n')
    {
        next();
        j++;
    }
    size_t line_len = j + lexer->col - 1;
    rewind(line_len);
    char sentence[line_len + 1];
    for (size_t i = 0; i < line_len; i++)
    {
        sentence[i] = specific(i);
    }
    sentence[line_len] = '\0';
    const size_t k = lexer->col;
    char spaces[k];
    for (size_t i = 0; i < k; i++)
    {
        spaces[i] = ' ';
    }
    spaces[k - 1] = '\0';

    printf("%s%s%s:%zu:%zu: %serror:%s Unknown Token\n", GREEN, BOLD, lexer->input->name,
           lexer->line, lexer->col, RED, RESET);
    printf("%zu %s|%s %s\n", lexer->line, YELLOW, RESET, sentence);
    printf("  %s| %s%s╰─%s%s `%s` is an unknown token %s\n", YELLOW, RED, spaces, arrows, LCYAN,
           word, RESET);
    return EXIT_FAILURE;
}
