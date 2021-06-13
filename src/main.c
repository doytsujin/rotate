#include "include/lexer.h"
#include "include/lib5717.h"
#include "include/log.h"


int main(int argc, char *argv[])
{
    char *default_file = "main.vr";
    file_t *file = file_read(argc > 1 ? argv[1] : default_file);
    if (!file) return EXIT_FAILURE;

    lexer_t lexer;
    lexer_init(&lexer, file);

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
