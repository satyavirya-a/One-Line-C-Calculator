#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Token {
    char item;
    struct Token* next;
}Token;

int isOperator(char symbol) {
    switch (symbol) {
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

int main() {

    return 0;
}