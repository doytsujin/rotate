#include "include/args.h"
#include "include/lexer.h"
#include <stdlib.h>

// TODO
int deal_the_args(int argc, char *argv[])
{
    if (argc > 2)
    {
        printf("doesn't support additional arguments rn\n");
        return EXIT_FAILURE;
    }
    // create file for interpreting
    file_t *file = file_read(argv[1]);
    // exit if file doesn't exist
    if (!file) return EXIT_FAILURE;
    // create lexer
    lexer_t lexer;
    if (lex(&lexer, file) == EXIT_FAILURE)
    {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int lex(lexer_t *lexer, file_t *file)
{
    // initialize a lexer with current file contents
    lexer_init(lexer, file);

    /// if lexing is failed, free memory then exit (status failure(1))
    if (lexer_lex(lexer) == EXIT_FAILURE)
    {
        free(file);
        tokens_free(lexer->output);
        //free(lexer->output);
        return EXIT_FAILURE;
    }

    // log into output.md
    // TODO:
    log_md(lexer, "output.md", "a");
    // end log

    // Free memory
    tokens_free(lexer->output);
    free(file);
    return EXIT_SUCCESS;
}
