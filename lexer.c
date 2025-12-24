#include <ctype.h>
#include <string.h>
#include "lexer.h"

FILE *src;
Token current;

void nextToken() {
    int c;
    while ((c = fgetc(src)) != EOF && isspace(c));

    if (c == EOF) {
        current.type = TOKEN_EOF;
        return;
    }

    if (isalpha(c)) {
        int i = 0;
        current.text[i++] = c;
        while (isalnum(c = fgetc(src)))
            current.text[i++] = c;
        current.text[i] = '\0';
        ungetc(c, src);

        if (!strcmp(current.text, "int"))
            current.type = TOKEN_INT;
        else
            current.type = TOKEN_ID;
        return;
    }

    if (isdigit(c)) {
        int i = 0;
        current.text[i++] = c;
        while (isdigit(c = fgetc(src)))
            current.text[i++] = c;
        current.text[i] = '\0';
        ungetc(c, src);
        current.type = TOKEN_NUM;
        return;
    }

    switch (c) {
        case '=': current.type = TOKEN_ASSIGN; break;
        case '+': current.type = TOKEN_PLUS; break;
        case '-': current.type = TOKEN_MINUS; break;
        case ';': current.type = TOKEN_SEMI; break;
        default: break;
    }
}
