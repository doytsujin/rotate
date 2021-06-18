#ifndef CLIB_5717_H
#define CLIB_5717_H

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/*****************\
  string functions
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

#endif // CLIB_5717_H
