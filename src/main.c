#include "include/lexer.h"
#include "include/lib5717.h"
#include "include/log.h"

int main(int argc, char *argv[])
{
    // default file name if argument [1] wasn't given
    char *default_file = "main.vr";

    // create file for interpreting
    file_t *file = file_read(argc > 1 ? argv[1] : default_file);

    // exit if file doesn't exist
    if (!file) return EXIT_FAILURE;

    // create lexer
    lexer_t lexer;
    // initialize a lexer with current file contents
    lexer_init(&lexer, file);

    /// if lexing is failed, free memory then exit (status failure(1))
    if (lexer_lex(&lexer) == EXIT_FAILURE)
    {
        free(file);
        free(lexer.output);
        return EXIT_FAILURE;
    }

    // log into output.md
    log_md(lexer, "output.md", "a");
    // end log

    // Free memory
    tokens_free(lexer.output);
    free(file);

    return EXIT_SUCCESS;
}
