#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char stack[MAX][MAX];  // Stack to hold infix expressions
int top = -1;

void push(char *);
char *pop();
int isOperator(char);
void postToInfix(char *);
int isEmpty();
int space(char);

int main() {
    char postfix[MAX];

    printf("Enter the postfix expression: ");
    fgets(postfix, MAX, stdin); // Using fgets to read input
    postfix[strcspn(postfix, "\n")] = '\0'; // Remove newline character

    postToInfix(postfix);
    
    if (!isEmpty()) {
        printf("The equivalent infix expression is: %s\n", pop());
    } else {
        printf("Invalid postfix expression!\n");
    }

    return 0;
}

void postToInfix(char *postfix) {
    char op1[MAX], op2[MAX], expr[MAX];
    for (int i = 0; i < strlen(postfix); i++) {
        char symbol = postfix[i];
        if (!space(symbol)) {
            if (isOperator(symbol)) {
                // Pop the second operand first (this was the last pushed)
                strcpy(op2, pop());
                // Pop the first operand
                strcpy(op1, pop());

                // Create a new string with the format (op1 operator op2)
                snprintf(expr, sizeof(expr), "(%s%c%s)", op1, symbol, op2);

                // Push the resulting expression back onto the stack
                push(expr);
            } else { // Operand
                char operand[2] = {symbol, '\0'}; // Convert symbol to a string
                push(operand);
            }
        }
    }
}

int space(char c) {
    // if the symbol is a blank space or a tab
    return c == ' ' || c == '\t';
}

int isOperator(char symbol) {
    return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^';
}

void push(char *expr) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return; // indicates end of function    
    }
    strcpy(stack[++top], expr);
}

char *pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

