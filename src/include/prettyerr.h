#ifndef PRETTY_PRINT_H
#define PRETTY_PRINT_H

#include "lexer.h"
#include "lib5717.h"

// error msg output
char *err_msgsfunc(lexer_t *lexer);

// advice for error msgs output
char *advice(lexer_t *lexer);

// if location of error is needed or not
bool is_location_needed(lexer_t *lexer);

// display error output
size_t lexer_lex_failure(lexer_t *lexer);

#endif // PRETTY_PRINT_ROTATE
