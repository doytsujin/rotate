#include "include/args.h"
#include "include/ast.h"

// TODO
int deal_the_args(const int argc, const char *argv[])
{
    if (argc > 2)
    {
        printf("doesn't support additional arguments rn\n");
        return EXIT_FAILURE;
    }

    // check file extension
    int len = strlen(argv[1]);
    const char *file_extension = &(argv[1])[len - 3];
    if (strcmp(file_extension, ".vr"))
    {
        printf("%s%s%s: %serror:%s %s%s\n", GREEN, BOLD, argv[1], RED, LCYAN,
               "file extension must be `.vr`", RESET);
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
        // free(lexer->output);
        return EXIT_FAILURE;
    }

    // log into output.md or output.json
    // INPUT ONLY MARKDOWN OR JSON FILES
    rotate_log(lexer, "output.json", "w");
    // end log

    // ast(lexer);

    // Free memory
    tokens_free(lexer->output);
    free(file);
    return EXIT_SUCCESS;
}
