#include "include/log.h"
#include <stdio.h>

void rotate_log(lexer_t *lexer, const char *filename, const char *filemode)
{
    // create output.md file
    // export tokens and source code
    // to the output.md or output.json
    const int len = strlen(filename);
    const char *file_extension = &(filename)[len - 2];
    bool markdown = true;
    if (strcmp(file_extension, ".md"))
    {
        markdown = false;
    }
    // bool json = !markdown;

    FILE *file_log = fopen(filename, filemode);
    // fclose(file_log);
    // file_log = stdout;

    if (markdown)
    {
        // output file name
        fprintf(file_log, "\n# FILE NAME: %s\n", lexer->input->name);
        // exit status
        fprintf(file_log, "## EXIT STATUS: 1\n");
        // file length
        fprintf(file_log, "### FILE LENGTH: %zu\n", lexer->input->length);
        fprintf(file_log, "---\n");
        fprintf(file_log, "%s", "----------------- file ---------------\n");
        // code in file
        fprintf(file_log, "```rust\n%s\n```\n", lexer->input->contents);
        fprintf(file_log, "%s", "--------------- Token output --------------\n");
        fprintf(file_log, "```rust\n");
        // tokens output
        for_each(lexer->output, tkn_t)
        {
            tkn_dump(tkn_t, file_log);
        }
        fprintf(file_log, "```\n");
        fprintf(file_log, "%s", "--------------- end --------------\n---\n");
    }
    else
    {
        fprintf(file_log, "{\n");
        fprintf(file_log, "\t\"file\":\"%s\",\n", lexer->input->name);
        fprintf(file_log, "\t\"length\":\"%zu\",\n", lexer->input->length);
        fprintf(file_log, "\t\"EXIT_STATUS\" : 0,");
        fprintf(file_log, "\n\t\"// PROGRAM START\":\"src code\",\n");
        fprintf(file_log, "%s", lexer->input->contents);
        for_each(lexer->output, tkn_t)
        {
            fprintf(file_log, "\n\t\"%s\": \"%s\",", tkn_type_describe(tkn_t->type), tkn_t->value);
        }
        fprintf(file_log, "\n}\n");
    }
    fclose(file_log);
}
