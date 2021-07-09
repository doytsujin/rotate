#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#include "lexer.h"
#include "lib5717.h"
#include "log.h"

// VERSION.SVERSION.SSVERSION
// if version is 1 and sversion and ssversion are 0
// becomes 1.0.0
#define VERSION 0
#define SVERSION 0
#define SSVERSION 1

// deal with arguments passed into main
int deal_the_args(const int argc, const char *argv[]);
// initialize the lexer and lex the input file
int lex(lexer_t *lexer, file_t *file);

#endif // ARGS_H
