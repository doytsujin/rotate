#include "include/token.h"

const char *tkn_type_describe(tkn_type_t type)
{
    switch (type)
    {
        case TknTypeIdentifier:
            return "id";
        case TknTypeAssign:
            return "assign'='";
        case TknTypeInteger:
            return "integer";
        case TknTypeNewline:
            return "newline'\\n'";
        case TknTypeSemiColon:
            return "semicolon';'";
        case TknTypeColon:
            return "colon':'";
        case TknTypeString:
            return "string";
        case TknTypeFunction:
            return "function'fn'";
        case TknTypePLUS:
            return "plus'+'";
        case TknTypeMINUS:
            return "minus'-'";
        case TknTypeMULTI:
            return "multiply'*'";
        case TknTypeDIV:
            return "divide'/'";
        case TknTypeLeftParen:
            return "leftparen')'";
        case TknTypeRightParen:
            return "rightparen'('";
        case TknTypeLeftCurly:
            return "leftcurlybrkt'{'";
        case TknTypeRightCurly:
            return "rightcurlybrkt'}'";
        case TknTypeLeftSQRBrackets:
            return "leftsqrbrkt']'";
        case TknTypeRightSQRBrackets:
            return "rightsqrbrkt'['";
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
            return "arrow'->'";
        case TknTypeGreater:
            return "greater'>'";
        case TknTypeLess:
            return "less'<'";
        case TknTypeTrue:
            return "bool:true";
        case TknTypeFalse:
            return "bool:false";
        case TknTypeDot:
            return "dot";
        case TknTypeNot:
            return "not'!'";
        case TknTypeMod:
            return "mod'%'";
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
            return "comma','";
        case TknTypeDollar:
            return "dollar'$'";
        case TknTypeDefault:
            return "default'_'";
        case TknTypeDivider:
            return "divider'|'";
        case TknTypePublic:
            return "public";
        case TknTypeMutable:
            return "mutable";
        case TknTypeCharType:
            return "char_type";
        case TknTypeFloatType:
            return "float_type";
        case TknTypeIntType:
            return "int_type";
        case TknTypeMatch:
            return "match";
        case TknTypeStringType:
            return "str_type";
        case TknTypeBoolType:
            return "bool_type";
        default:
            return "???";
    }
}

void tkn_dump(tkn_t *tkn)
{
    fprintf(stderr,
            "Token '\x1b[1m\x1b[93m%s\x1b[0m' at \x1b[94m%s:%zu:%zu\x1b[0m with text "
            "\"\x1b[1m\x1b[92m %s "
            "\x1b[0m\"\n",
            tkn_type_describe(tkn->type), tkn->pos.file, tkn->pos.line, tkn->pos.col, tkn->value);
}
