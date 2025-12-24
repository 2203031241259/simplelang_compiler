#include <stdio.h>
#include "ast.h"

FILE *out;

void gen_expr(AST* n) {
    if (n->type == AST_NUM)
        fprintf(out, "LDA #%d\n", n->value);
    else if (n->type == AST_VAR)
        fprintf(out, "LDA %s\n", n->name);
}

void generate(AST* n, const char* file) {
    out = fopen(file, "w");

    while (n) {
        if (n->type == AST_ASSIGN) {
            gen_expr(n->right);
            fprintf(out, "STA %s\n", n->name);
        }
        n = n->next;
    }

    fclose(out);
}
