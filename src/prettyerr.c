#include "include/prettyerr.h"
#include "include/lexer.h"
#include <stdio.h>

char *err_msgsfunc(lexer_t *lexer)
{
    switch (lexer->error_type)
    {
        case 1:
            return "The char must contain 1 char only";
        case 2:
            return "The quote is not closed";
        case 3:
            return "The double quote is not closed";
        case 4:
            return "The file is empty";
    }
    return "char/token is unknown";
}

bool is_location_needed(lexer_t *lexer)
{
    size_t x = lexer->error_type;
    switch (x)
    {
        case 4:
            return false;
        default:
            return true;
    }
    return true;
}

// failure display
int lexer_lex_failure(lexer_t *lexer)
{

    char *err_msg = err_msgsfunc(lexer);
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

    const size_t k = lexer->error_type == 1 ? lexer->col - 1 : lexer->col;
    char spaces[k];
    for (size_t i = 0; i < k; i++)
    {
        if (k == 1)
        {
            spaces[0] = 0;
            spaces[1] = 0;
        }
        spaces[i] = ' ';
    }
    spaces[k - 1] = k == 1 ? 0 : 0;

    printf("%s%s%s:%zu:%zu: %serror:%s %s\n", GREEN, BOLD, lexer->input->name, lexer->line,
           lexer->col, RED, RESET, err_msg);

    if (print_location)
    {
        printf("%zu %s┃%s %s\n", lexer->line, YELLOW, RESET, sentence);
        printf("  %s┃ %s%s╰─%s%s %s %s\n", YELLOW, RED, spaces, arrows, LYELLOW, err_msg, RESET);
    }
    return EXIT_FAILURE;
}
