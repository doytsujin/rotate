#include "include/prettyerr.h"

char *err_msgsfunc(lexer_t *lexer)
{
    switch (lexer->error_type)
    {
        
        case NOT_CLOSED_CHAR:
            return "The char is not closed.";
        case NOT_CLOSED_STRING:
            return "The string is not closed.";
        case END_OF_FILE:
            return "reached end of file";
        case FILE_EMPTY:
            return "The file is empty.";
        default:
            break;
    }
    return "The char/token is unknown.";
}

char *advice(lexer_t *lexer)
{

    switch (lexer->error_type)
    {
        
        case NOT_CLOSED_CHAR:
            return "Close the char with a quote";
        case NOT_CLOSED_STRING:
            return "Close the string with a double quote";
        case END_OF_FILE:
            return "Reached end of file";
        case FILE_EMPTY:
            return "Do not compile empty files.";
        default:
            break;
    }
    return "Check this Unknown token.";
}

// to display error location
bool is_location_needed(lexer_t *lexer)
{
    size_t x = lexer->error_type;
    switch (x)
    {
        case END_OF_FILE:
            return false;
        case FILE_EMPTY:
            return false;
        default:
            break;
    }
    return true;
}

// failure display
int lexer_lex_failure(lexer_t *lexer)
{

    char *err_msg = err_msgsfunc(lexer);
    char *err_advice = advice(lexer);
    bool print_location = is_location_needed(lexer);
    size_t len = lexer->length;

    // char word[len + 1];
    char arrows[len + 1];
    for (size_t i = 0; i < len; i++)
    {
        // word[i] = specific(i) != '\n'? specific(i) : 0;
        arrows[i] = '-';
    }
    // word[len] = 0;
    arrows[len] = 0;

    size_t j = 0;
    while (current() != '\n' && current() != 0)
    {
        next();
        j++;
    }
    size_t line_len = j + lexer->col - 1;
    rewind_macro(line_len);
    char sentence[line_len + 1];

    for (size_t i = 0; i < line_len; i++)
    {
        sentence[i] = specific(i);
    }
    sentence[line_len] = 0;

    // count number of digits in line number
    size_t i = lexer->line; // variable declaration
    size_t count = 0;       // variable declaration
    while (i != 0)
    {
        i = i / 10;
        count++;
    }

    const size_t k = lexer->col + 1;
    char spaces[k], space_line[count];
    for (size_t i = 0; i < k; i++)
    {
        if (k == 1)
        {
            spaces[0] = 0;
            spaces[1] = 0;
        }
        spaces[i] = ' ';
    }
    for (size_t i = 0; i < count; i++)
    {
        if (count == 1)
        {
            space_line[0] = 0;
            space_line[1] = 0;
        }
        space_line[i] = ' ';
    }
    spaces[k - 1] = k == 1 ? 0 : 0;
    space_line[count - 1] = count == 1 ? 0 : 0;

    // Printing phase
    printf("%s%s%s:%zu:%zu: %s\nerror:%s %s\n", GREEN, BOLD, lexer->input->name, lexer->line,
           lexer->col, RED, RESET, err_msg);

    if (print_location)
    {
        printf("%zu %s┃%s %s\n", lexer->line, YELLOW, RESET, sentence);
        printf("%s  %s┃%s%s╰─%s%s %s %s\n", space_line, YELLOW, RED, spaces, arrows, LYELLOW, err_advice, RESET);
    }
    else
    {
        printf("%s %s %s\n", LYELLOW, err_advice, RESET);
    }
    return EXIT_FAILURE;
}
