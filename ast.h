#ifndef AST_H
#define AST_H

typedef enum {
    AST_DECL,
    AST_ASSIGN,
    AST_BINOP,
    AST_NUM,
    AST_VAR
} ASTType;

typedef struct AST {
    ASTType type;
    char name[32];
    int value;
    char op;
    struct AST *left;
    struct AST *right;
    struct AST *next;
} AST;

AST* new_node(ASTType type);

#endif
