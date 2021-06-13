#ifndef C5717LIB_H
#define C5717LIB_H

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// string functions

// convert to upper case
void to_upper_case(char *str);
// convert to lower case
void to_lower_case(char *str);
// add 2 strings into one string
char *concat_str(const char *str1, const char *str2);
// get length of string with null terminator
size_t str_length(const char *str);

#endif // C5717LIB_H
