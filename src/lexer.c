#include "include/lexer.h"
#include "include/prettyerr.h"

// lexer initialization
void lexer_init(lexer_t *lexer, file_t *input)
{
    // init default values
    lexer->output = new_vec(tkn_t);
    lexer->input = input;
    lexer->index = 0;
    lexer->line = 1;
    lexer->col = 1;
    lexer->length = 1;
    lexer->error_type = UNKNOWN;
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
    if (!peek()) lexer->error_type = END_OF_FILE;

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
static void lexer_tkn(lexer_t *lexer, tkn_type_t type)
{
    const tkn_t token =
        tkn_make(pos_make(lexer->line, lexer->col, lexer->input->name),
                 utils_strndup(lexer->input->contents + lexer->index, length()), type);
    for (size_t i = 0; i < length(); i++)
    {
        lexer_advance(lexer);
    }
    vec_push(lexer->output, token);
}

// lex multicharaters
size_t lexer_multichar(lexer_t *lexer)
{
    size_t save_index = lexer->index;
    size_t save_line = lexer->line;
    size_t save_col = lexer->col;
    size_t save_length = lexer->length;

    // Only called when first char is start of identifier
    // So we can safely advance
    lexer_advance(lexer);
    // Length of identifier/Typeword
    length() = 1; // already matched 1 char
    size_t length = 1;
    while (isalnum(current()) || current() == '_')
    {
        lexer_advance(lexer);
        length++;
    }
    lexer->index = save_index;
    lexer->line = save_line;
    lexer->col = save_col;
    lexer->length = save_length;
    tkn_type_t type = TknTypeIdentifier;

    // check for matched words
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
    length() = length;
    lexer_tkn(lexer, type);
    return EXIT_SUCCESS;
}

// lexer for single characater
static size_t lexer_single(lexer_t *lexer)
{

    if (lexer->input->contents[0] == 0)
    {
        lexer->error_type = END_OF_FILE;
        return EXIT_FAILURE;
    }
    lexer_skip_white(lexer);
    const char lex_char = current();
    length() = 1;

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
        length() = i;
        lexer_tkn(lexer, reached_dot ? TknTypeFloat : TknTypeInteger);
        return EXIT_SUCCESS;
    }
    // string lexer
    else if (lex_char == '"')
    {
        // string lexer
        size_t save_index = lexer->index;
        size_t save_line = lexer->line;
        size_t save_col = lexer->col;
        length() = 1;
        lexer_advance(lexer);
        while (current() != '\"')
        {
            // printf("%c\n", current());
            if (current() == 0)
            {
                lexer->error_type = NOT_CLOSED_STRING;
                return EXIT_FAILURE;
            }
            lexer_advance(lexer);
            add_len();
        }

        add_len();
        lexer->index = save_index;
        lexer->line = save_line;
        lexer->col = save_col;
        lexer_tkn(lexer, TknTypeString);
        return EXIT_SUCCESS;
    }

    // char lexer
    if (lex_char == '\'')
    {
        // char lexer
        size_t save_index = lexer->index;
        size_t save_line = lexer->line;
        size_t save_col = lexer->col;
        length() = 1;
        lexer_advance(lexer);
        while (current() != '\'')
        {
            // printf("current(%c)\npast(%c)\npeek(%c)\nlength(%zu)\n", current(), past(), peek(),
            // length());

            if (isspace(current()) && peek() != '\'')
            {
                lexer->error_type = NOT_CLOSED_CHAR;
                return EXIT_FAILURE;
            }
            if (current() == 0)
            {
                lexer->error_type = END_OF_FILE;
                return EXIT_FAILURE;
            }
            if (length() > 2)
            {
                lexer->error_type = NOT_CLOSED_CHAR;
                return EXIT_FAILURE;
            }
            if (length() == 2 && past() == '\\' && current() != '\\')
            {
                lexer_advance(lexer);
                add_len();
                break;
            }
            if (length() > 1 && past() != '\\' && (peek() == '\'' || peek() == '\\'))
            {
                lexer->error_type = NOT_CLOSED_CHAR;
                return EXIT_FAILURE;
            }
            lexer_advance(lexer);
            add_len();
            // printf("current %c and length %zu, peek %c and past %c\n", current(), length(),
            // peek(), past());
        }

        add_len();
        lexer->index = save_index;
        lexer->line = save_line;
        lexer->col = save_col;
        lexer_tkn(lexer, TknTypeChar);
        return EXIT_SUCCESS;
    }

    // lexer for single chars
    switch (lex_char)
    {
        case '_':
            lexer_tkn(lexer, TknTypeDefault);
            break;
        case '|':
            if (peek() == '|')
            {
                add_len();
                lexer_tkn(lexer, TknTypeOr);
                lexer_advance(lexer);
            }
            else
            {
                lexer_tkn(lexer, TknTypeDivider);
            }
            break;
        case '=':
            if (peek() == '=')
            {
                add_len();
                lexer_tkn(lexer, TknTypeEqualEqual);
                lexer_advance(lexer);
            }
            else
            {
                lexer_tkn(lexer, TknTypeEqual);
            }
            break;
        case ':':
            lexer_tkn(lexer, TknTypeColon);
            break;
        case ';':
            lexer_tkn(lexer, TknTypeSemiColon);
            break;
        case '\n':
            lexer_tkn(lexer, TknTypeNewline);
            break;
        case '+':
            lexer_tkn(lexer, TknTypePLUS);
            break;
        case '-':
            if (peek() == '>')
            {
                add_len();
                lexer_tkn(lexer, TknTypeArrow);
                lexer_advance(lexer);
            }
            else
            {
                lexer_tkn(lexer, TknTypeMINUS);
            }
            break;
        case '*':
            lexer_tkn(lexer, TknTypeStar);
            break;
        case '/':
            if (peek() == '/')
            {
                while (!is_eof() && current() != '\n' && current() != 0)
                {
                    lexer_advance(lexer);
                }
            }
            else if (peek() == '*')
            {
                bool end_comment = false;
                while (!is_eof() && current() != 0 && !end_comment)
                {
                    if ((past() == '*' && current() == '/')) end_comment = true;
                    lexer_advance(lexer);
                }
            }
            else if (peek() == '+')
            {
                bool end_comment = false;
                while (!is_eof() && current() != 0 && !end_comment)
                {
                    if ((past() == '+' && current() == '/')) end_comment = true;
                    lexer_advance(lexer);
                }
            }
            else
            {
                lexer_tkn(lexer, TknTypeDIV);
            }
            break;
        case '(':
            lexer_tkn(lexer, TknTypeLeftParen);
            break;
        case ')':
            lexer_tkn(lexer, TknTypeRightParen);
            break;
        case '{':
            lexer_tkn(lexer, TknTypeLeftCurly);
            break;
        case '}':
            lexer_tkn(lexer, TknTypeRightCurly);
            break;
        case '[':
            lexer_tkn(lexer, TknTypeLeftSQRBrackets);
            break;
        case ']':
            lexer_tkn(lexer, TknTypeRightSQRBrackets);
            break;
        case '>':
            lexer_tkn(lexer, TknTypeGreater);
            break;
        case '<':
            lexer_tkn(lexer, TknTypeLess);
            break;
        case '.':
            if (peek() == '.')
            {
                add_len();
                lexer_tkn(lexer, TknTypeTo);
                lexer_advance(lexer);
            }
            else
                lexer_tkn(lexer, TknTypeDot);
            break;
        case '$':
            lexer_tkn(lexer, TknTypeDollar);
            break;
        case '!':
            lexer_tkn(lexer, TknTypeNot);
            break;
        case '%':
            lexer_tkn(lexer, TknTypeMod);
            break;
        case ',':
            lexer_tkn(lexer, TknTypeComma);
            break;
        case '&':
            if (peek() == '&')
            {
                add_len();
                lexer_tkn(lexer, TknTypeAnd);
                lexer_advance(lexer);
                break;
            }
            else
            {
                return EXIT_FAILURE;
            }
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
size_t lexer_lex(lexer_t *lexer)
{
    lexer->index = 0;
    lexer->line = 1;
    lexer->col = 1;
    // printf("length: %zu\n", strlen(lexer->input->contents));
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
