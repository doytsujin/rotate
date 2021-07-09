#ifndef LOG_H
#define LOG_H

#include "lexer.h"

void rotate_log(lexer_t *lexer, const char *filename, const char *filemode);

#endif
