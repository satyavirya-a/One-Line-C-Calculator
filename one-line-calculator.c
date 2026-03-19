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

int evaluateOperator(int a, int b, char symbol) {
	switch (symbol) {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
        case '^': return a^b;
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
//          postfix[++idx] = c; // supaya bisa bedain kalau angka lebih dari 1 digit
			i++;
			continue;
        }

        else if (c == '(') {
            stack[++top] = c;
        }

        else if (c == ')') {
            while (stack[top] != '(') {
                postfix[++idx] = stack[top--];
            }
            top--; //hilangkan (
        }

        else if (isOperator(c) > 0) {
            while (isOperator(stack[top]) >= isOperator(c) && stack[top] != '(') {
                postfix[++idx] = stack[top--];
            }
            
            stack[++top] = c;
        
        }

        else if (isOperator(c) == 0 && c != '(' && c != ')'){
            postfix[++idx] = c;
        }
        

        i++;
    }

    while (top >= 0) {
        postfix[++idx] = stack[top--];
    }

    postfix[++idx] = '\0';

}

int evaluatePostfix(char* postfix) {
	int topStack = -1;
	int idxNum = 0;
	int idx = 0;
	
	int stack[100] = {0};
	char strNum[10]; //maksimal digit angka 10
	
	
	while (postfix[idx] != '\0') {
		char c = postfix[idx];
//		printf("now %c\n", c);
		
		if ( c >= '0' && c <= '9') {
//			strNum[idxNum++] = c;
			int temp = c - '0';
			stack[++topStack] = temp;
			
//			printf("stack now \n");
//			int i;
//			for (i = 0; i <= topStack; i++) {
//				printf("%d ", stack[i]);
//			}
//			printf("\n");
		}
		
//		else if (c == ' ') {
//			stack[topStack++] = atoi(strNum);
//			strNum[0] = '\0';
//			idxNum = 0;
//		}
		
		else if (isOperator(c) > 0) {
			int b = stack[topStack--];
			int a = stack[topStack--];
//			printf("operator %d %d %c\n", a, b, c);
			int result = evaluateOperator(a,b, c);
			stack[++topStack] = result;
		}
		
		
		idx++;
	}
	
	return stack[topStack];
}

void menu() {
    char buffer[100];
    printf("Masukan Angka dan Operator yang ingin dievaluasi [maks 100 char]: ");
    scanf("%[^\n]", buffer ); getchar();

    char* postfix = (char*)malloc(strlen(buffer) + 1);
    infixToPostfix(buffer, postfix);
    
//    printf("%s\n", buffer);
//    printf("%s\n", postfix);
    
    int resultFinal = evaluatePostfix(postfix);
    printf("Final Result = %d\n", resultFinal);
    return;
}


int main() {	

    menu();

    return 0;
}
