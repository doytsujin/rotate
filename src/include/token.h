#ifndef TOKEN_H
#define TOKEN_H

#include <stdio.h>
#include <stdlib.h>

// show position of tokens
#define pos_make(line, col, file)                                                                  \
    (pos_t)                                                                                        \
    {                                                                                              \
        line, col, file                                                                            \
    }

// position datarefs for tokens
typedef struct
{
    size_t line;
    size_t col;
    const char *file;
} pos_t;

// An enum describing all the different types of tokens
typedef enum
{
    TknTypeIdentifier,
    TknTypeEqual,
    TknTypeLet,
    TknTypeInteger,
    TknTypeFloat,
    TknTypeIntType,
    TknTypeFloatType,
    TknTypeStringType,
    TknTypeCharType,
    TknTypeBoolType,
    TknTypeNewline,
    TknTypeSemiColon,
    TknTypeColon,
    TknTypeString,
    TknTypeFunction,
    TknTypePLUS,
    TknTypeMINUS,
    TknTypeStar,
    TknTypeDIV,
    TknTypeLeftParen,
    TknTypeRightParen,
    TknTypeLeftCurly,
    TknTypeRightCurly,
    TknTypeLeftSQRBrackets,
    TknTypeRightSQRBrackets,
    TknTypeReal,
    TknTypeChar,
    TknTypeReturn,
    TknTypeImport,
    TknTypeIf,
    TknTypeElse,
    TknTypeFor,
    TknTypeWhile,
    TknTypeForEach,
    TknTypeArrow,
    TknTypeGreater, // >
    TknTypeLess,    // <
    TknTypeTrue,
    TknTypeFalse,
    TknTypeDot,
    TknTypeNot, // "!"
    TknTypeMod,
    TknTypeAnd,
    TknTypeOr,
    TknTypePrint,
    TknTypeDoubleQuotes,
    TknTypeQuote,
    TknTypeComma,
    TknTypeDollar,
    TknTypeDefault, // '_'
    TknTypePublic,  // 'pub'
    TknTypeDivider,
    TknTypeMutable,
    TknTypeMatch,
    TknTypeAs,
    TknTypeEqualEqual, // ==
    TknTypeBreak,
    TknTypeAccess, // ::
} tkn_type_t;

// A struct describing a token
typedef struct
{
    pos_t pos;
    char *value;
    tkn_type_t type;
} tkn_t;

// Creates a token
#define tkn_make(pos, value, type)                                                                 \
    (tkn_t)                                                                                        \
    {                                                                                              \
        pos, value, type                                                                           \
    }

// describe the token type
const char *tkn_type_describe(tkn_type_t type);

// dump token
void tkn_dump(tkn_t *tkn, FILE *file_log);

// end of header
#endif /* TOKEN_H */
