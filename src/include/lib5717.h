#ifndef CLIB_5717_H
#define CLIB_5717_H

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/*****************\
 string  functions
\*****************/

// convert to upper case
void to_upper_case(char *str);
// convert to lower case
void to_lower_case(char *str);
// add 2 strings into one string
char *concat_str(const char *str1, const char *str2);
// get length of string with null terminator
size_t str_length(const char *str);

/*****************\
   math functions
\*****************/

// get number of digits in number
size_t get_number_of_digits(int number);

/*****************\
  color constants
\*****************/

/// colors to make output look nicer
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define PINK "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

#define BOLD "\x1b[1m"
#define FAINT "\x1b[2m"

#define BLACK "\x1b[30m"
#define WHITE "\x1b[37m"
#define DEFAULT "\x1b[39m"
#define LGRAY "\x1b[90m"
#define LRED "\x1b[91m"
#define LGREEN "\x1b[92m"
#define LYELLOW "\x1b[93m"
#define LBLUE "\x1b[94m"
#define LMAGENTA "\x1b[95m"
#define LCYAN "\x1b[96m"
#define LWHITE "\x1b[97m"

#endif // CLIB_5717_H
