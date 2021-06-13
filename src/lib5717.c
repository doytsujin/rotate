#include "include/lib5717.h"

void to_upper_case(char *str)
{
    for (size_t i = 0; str[i] != 0; i++)
    {
        if (isalpha(str[i])) str[i] = toupper(str[i]);
    }
}

void to_lower_case(char *str)
{
    for (size_t i = 0; str[i] != 0; i++)
    {
        if (isalpha(str[i])) str[i] = tolower(str[i]);
    }
}

char *concat_str(const char *str1, const char *str2)
{
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    char *res = malloc(len1 + len2 + 1);
    memcpy(res, str1, len1);
    memcpy(res + len1, str2, len2);
    res[len1 + len2] = 0;
    return res;
}