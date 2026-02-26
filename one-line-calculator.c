#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void infixToPostfix(char* infix, char* postfix) {
    char stack[100];

    int top = -1;
    int idx = -1;
    int i = 0;

    while (infix[i] != '\0') {
        char c = infix[i];

        if (c == ' ') {
            i++;
            continue;
        }

        if (c == '(') {
            stack[++top] = c;
        }

        if (c == ')') {
            while (stack[top] != '(') {
                postfix[++idx] = stack[top--];
            }
            top--; //hilangkan (
        }

        if (isOperator(c) > 0) {
            while (isOperator(stack[top]) >= isOperator(c) && stack[top] != '(') {
                postfix[++idx] = stack[top--];
            }
            
            stack[++top] = c;
        
        }

        if (isOperator(c) == 0 && c != '(' && c != ')'){
            postfix[++idx] = c;
        }
        

        i++;
    }

    while (top >= 0) {
        postfix[++idx] = stack[top--];
    }

    postfix[++idx] = '\0';

}

void menu() {
    char buffer[100];
    printf("Masukan Angka dan Operator yang ingin dievaluasi [maks 100 char]: ");
    scanf("%[^\n]", buffer ); getchar();

    char* postfix = (char*)malloc(strlen(buffer) + 1);
    infixToPostfix(buffer, postfix);
    
    printf("%s\n", buffer);
    printf("%s\n", postfix);
    return;
}


int main() {

    menu();

    return 0;
}