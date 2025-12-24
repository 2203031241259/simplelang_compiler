#include <stdio.h>
#include "ast.h"
#include "lexer.h"

AST* parse_program();
void generate(AST*, const char*);

int main() {
    src = fopen("examples/input.sl", "r");
    if (!src) {
        printf("Input file not found\n");
        return 1;
    }

    AST* tree = parse_program();
    generate(tree, "examples/output.asm");

    printf("Compilation successful!\n");
    return 0;
}
