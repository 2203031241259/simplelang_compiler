#include <stdio.h>
#include "ast.h"
#include "lexer.h"

AST* parse_program();
void generate(AST*, const char*);

int main(void) {
    src = fopen("input.sl", "r");
    if (!src) {
        printf("Input file not found: input.sl\n");
        return 1;
    }

    AST* tree = parse_program();
    generate(tree, "output.asm");

    printf("Compilation successful!\n");
    fclose(src);
    return 0;
}
