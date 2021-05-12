#include "include/includes.h"

const char *tkn_type_describe(tkn_type_t type)
{
    switch (type)
    {
    case TknTypeIdentifier:
        return "id";
    case TknTypeAssign:
        return "assign";
    case TknTypeInteger:
        return "integer";
    case TknTypeNewline:
        return "newline";
    case TknTypeSemiColon:
        return "semicolon";
    case TknTypeColon:
        return "colon";
    case TknTypeString:
        return "string";
    case TknTypeFunction:
        return "function";
    case TknTypePLUS:
        return "plus";
    case TknTypeMINUS:
        return "minus";
    case TknTypeMULTI:
        return "multiply";
    case TknTypeDIV:
        return "divide";
    case TknTypeLeftParen:
        return "left_parentheses";
    case TknTypeRightParen:
        return "right_parentheses";
    case TknTypeLeftCurly:
        return "left_curly_brackets";
    case TknTypeRightCurly:
        return "right_curly_brackets";
    case TknTypeLeftSQRBrackets:
        return "left_sqr_brackets";
    case TknTypeRightSQRBrackets:
        return "right_sqr_brackets";
    case TknTypeReal:
        return "real";
    case TknTypeChar:
        return "char";
    case TknTypeReturn:
        return "return";
    case TknTypeImport:
        return "import";
    case TknTypeIf:
        return "if";
    case TknTypeElse:
        return "else";
    case TknTypeFor:
        return "for";
    case TknTypeWhile:
        return "while";
    case TknTypeForEach:
        return "foreach";
    case TknTypeArrow:
        return "arrow";
    case TknTypeGreater:
        return "greater than";
    case TknTypeLess:
        return "less than";
    case TknTypeTrue:
        return "bool:true";
    case TknTypeFalse:
        return "bool:false";
    case TknTypeDot:
        return "dot";
    case TknTypeNot:
        return "not";
    case TknTypeMod:
        return "mod";
    case TknTypeAnd:
        return "and";
    case TknTypeOr:
        return "or";
    case TknTypePrint:
        return "print";
    case TknTypeDoubleQuotes:
        return "double quotes";
    case TknTypeQuote:
        return "quote";
    case TknTypeFloat:
        return "float";
    case TknTypeLet:
        return "let";
    case TknTypeComma:
        return "comma";
    default:
        return "???";
    }
}

void tkn_dump(tkn_t *tkn)
{
    fprintf(stderr, "Token '%s' at %s:%zu:%zu with text \"%s\"\n", tkn_type_describe(tkn->type),
            tkn->pos.file, tkn->pos.line, tkn->pos.col, tkn->value);
}

