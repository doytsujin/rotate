#ifndef AST_H
#define AST_H

/*

struct BlockStmt;

struct PrintStmt;

struct IfStmt;

typedef struct
{

    enum
    {
        BLOCK_STMT,
        IF_STMT,
        BREAK,

    } type;
} Stmt;
typedef struct
{
    BlockStmt *block_stmt;
    IfStmt *if_stmt;
} data;

typedef struct
{

} Expr;

struct IfStmt
{
    Expr *cond;
    Stmt *body;
};

struct StmtList
{
    Stmt *stmt;
    struct StmtList *next;
};
struct BlockStmt
{

};

*/

#endif /* AST_H */
