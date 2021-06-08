#include "include/lexer.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    char *default_file = "./examples/hello.vr";
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


    // log
    FILE *file_log = fopen("./output.md", "a");
    fprintf(file_log, "\n# FILE NAME: %s\n", lexer.input->name);
    fprintf(file_log, "## EXIT_STATUS 1 \n");
    fprintf(file_log, "### FILE LENGTH: %zu\n", lexer.input->length);
    fprintf(file_log, "---\n");
    fprintf(file_log, "%s", "----------------- file ---------------\n");
    fprintf(file_log, "```rust\n%s\n```\n", lexer.input->contents);
    fprintf(file_log, "%s", "--------------- Token output --------------\n");
    fprintf(file_log, "```rust\n");
    for_each(lexer.output, tkn_ptr)
    {
        tkn_dump(tkn_ptr, file_log);
    } 
    fprintf(file_log, "```\n");
    fprintf(file_log, "%s", "--------------- end --------------\n---\n");
    fclose(file_log);
    // end log

    // Free memory
    tokens_free(lexer.output);
    free(file);

    return EXIT_SUCCESS;
}
