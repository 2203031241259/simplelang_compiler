#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>

#define MAX 64

typedef enum {
    TOKEN_INT,
    TOKEN_ID,
    TOKEN_NUM,
    TOKEN_ASSIGN,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_SEMI,
    TOKEN_EOF
} TokenType;

typedef struct {
    TokenType type;
    char text[MAX];
} Token;

extern FILE *src;
extern Token current;

void nextToken();

#endif
