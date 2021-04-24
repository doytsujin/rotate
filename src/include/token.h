#ifndef TOKEN_H
#define TOKEN_H

#include <stddef.h>

// show position of tokens
#define pos_make(line, col, file) \
	(pos_t) { line, col, file }

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
	TknTypeAssign,
	TknTypeInteger, 
	TknTypeNewline,
	TknTypeSemiColon,
	TknTypeColon,
	TknTypeString, 
	TknTypeFunction,
	TknTypePLUS,
	TknTypeMINUS,
    TknTypeMULTI,
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
	TknTypeLess, // < 
	TknTypeTrue,
	TknTypeFalse,
	TknTypeDot,
	TknTypeNot, // "!"
	TknTypeMod,
	TknTypeAnd,
	TknTypeOr,
} tkn_type_t;

// A struct describing a token
typedef struct
{
	pos_t pos;
	char *value;
	tkn_type_t type;
} tkn_t;

// Creates a token
#define tkn_make(pos, value, type) \
	(tkn_t) { pos, value, type }

// describe the token type
const char *tkn_type_describe(tkn_type_t type);

// dump token
void tkn_dump(tkn_t *tkn);

// end of header
#endif /* TOKEN_H */
