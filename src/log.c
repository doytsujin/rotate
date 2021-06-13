#include "include/log.h"

void log_md(lexer_t lexer, const char *filename, const char *filemode)
{
    // create output.md file
    // export tokens and source code
    // to the output.md
    FILE *file_log = fopen(filename, filemode);
    fprintf(file_log, "\n# FILE NAME: %s\n", lexer.input->name);
    fprintf(file_log, "## EXIT STATUS: 1 \n");
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
}
