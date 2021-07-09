#include "include/lib5717.h"

// convert to upper case
char *to_upper_case(char *str)
{
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        if (isalpha(str[i])) str[i] = toupper(str[i]);
    }
    return str;
}

// convert to lower case
char *to_lower_case(char *str)
{
    for (size_t i = 0; str[i] != '\0'; i++)
    {
        if (isalpha(str[i])) str[i] = tolower(str[i]);
    }
    return str;
}

// add 2 strings into one string
char *concat_str(const char *str1, const char *str2)
{
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    char *res = malloc(len1 + len2 + 1);
    memcpy(res, str1, len1);
    memcpy(res + len1, str2, len2);
    res[len1 + len2] = '\0';
    return res;
}

// get length of string with null terminator
size_t str_length(const char *str)
{
    return (strlen(str) + 1);
}

// get number of digits in number
size_t get_number_of_digits(const int number)
{
    size_t count = 0;
    int num = number;
    if (num < 0)
    {
        num *= -1;
    }
    if (num < 9)
    {
        return 1;
    }
    else
    {
        while (num > 0)
        {
            num /= 10;
            count++;
        }
    }
    return count;
}
