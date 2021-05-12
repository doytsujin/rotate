#ifndef AST_H
#define AST_H

typedef struct
{
    enum
    {
        PrintStmt,
        IfStmt,
        FuncCall,
        ReturnStmt,
        WhileLoop,
        ForEachLoop,
        DecVarStmt,
        ImportFile,
    } type;
} node_t;

typedef struct
{
    enum
    {
        LiteralExpr,
        BinaryExpr,
        CallExpr,
        IntExpr,
        FloatExpr,

    } type;
} expr_t;

typedef struct
{
    node_t node;
    expr_t value;
} print_statement_t;

void get_tree();

#endif /* AST_H */
