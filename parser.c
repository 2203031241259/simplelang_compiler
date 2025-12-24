#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "lexer.h"

AST* new_node(ASTType type) {
    AST* n = malloc(sizeof(AST));
    memset(n, 0, sizeof(AST));
    n->type = type;
    return n;
}

AST* parse_expression() {
    AST* node;

    if (current.type == TOKEN_NUM) {
        node = new_node(AST_NUM);
        node->value = atoi(current.text);
        nextToken();
        return node;
    }

    node = new_node(AST_VAR);
    strcpy(node->name, current.text);
    nextToken();
    return node;
}

AST* parse_statement() {
    if (current.type == TOKEN_INT) {
        nextToken();
        AST* d = new_node(AST_DECL);
        strcpy(d->name, current.text);
        nextToken(); // identifier
        nextToken(); // ;
        return d;
    }

    AST* a = new_node(AST_ASSIGN);
    strcpy(a->name, current.text);
    nextToken(); // id
    nextToken(); // =
    a->right = parse_expression();
    nextToken(); // ;
    return a;
}

AST* parse_program() {
    AST *head = NULL, *tail = NULL;
    nextToken();

    while (current.type != TOKEN_EOF) {
        AST* stmt = parse_statement();
        if (!head) head = tail = stmt;
        else {
            tail->next = stmt;
            tail = stmt;
        }
    }
    return head;
}
