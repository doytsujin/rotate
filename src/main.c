#include "include/lexer.h"

int main(int argc, char *argv[])
{
    file_t *file = file_read(argc > 1 ? argv[1] : "./examples/errors/2char.vr");
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
    FILE *file_log = fopen("./log/output.md", "wb");
    fprintf(file_log, "# EXIT_STATUS 1 \n");
    fprintf(file_log, "## file name: %s\n", lexer.input->name);
    fprintf(file_log, "## file length: %zu\n", lexer.input->length);
    fprintf(file_log, "%s", "----------------- file ---------------\n");
    fprintf(file_log, "```rust\n%s\n```\n", lexer.input->contents);
    fprintf(file_log, "%s", "--------------- end file --------------\n");
    fprintf(file_log, "```rust\n");
    for_each(lexer.output, tkn_ptr)
    {
        tkn_dump(tkn_ptr, file_log);
    } // end log
    fprintf(file_log, "```\n");

    tokens_free(lexer.output);
    free(file);
    return EXIT_SUCCESS;
}
