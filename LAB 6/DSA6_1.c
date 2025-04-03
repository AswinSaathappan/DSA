//InfixtoPostfix                                                                                                                        #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char stack[MAX];
char infix[MAX];
char postfix[MAX];
int top = -1;

void push(char);
char pop();
int isEmpty();
void inToPost();
int space(char);
void print();
int precedence(char);

int main() {
    printf("Enter the infix expression: ");
    gets(infix);
    inToPost();
    print();
    return 0;
}

void inToPost() {
    int i, j = 0;
    char next;
    char symbol;
    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];
        // if symbol is not a whitespace
        if (!space(symbol)) {
            switch (symbol) {
                case '(':
                    push(symbol);
                    break;

                case ')':
                    // Corrected loop: Pop until '(' is found
                    while ((next = pop()) != '(') {
                        postfix[j++] = next;
                    }
                    break;

                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                    // Pop all operators from the stack with higher or equal precedence
                    while (!isEmpty() && precedence(stack[top]) >= precedence(symbol) && stack[top] != '(') {
                        postfix[j++] = pop();
                    }
                    push(symbol);
                    break;

                default: // if the symbol is an operand
                    postfix[j++] = symbol;
            }
        }
    }
    // Pop all remaining operators in the stack
    while (!isEmpty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; // Ensure null-termination of the postfix string
}

int space(char c) {
    // if the symbol is a blank space or a tab
    return c == ' ' || c == '\t';
}

int precedence(char symbol) {
    switch (symbol) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0; // This case covers '(' and other non-operator characters
    }
}

void print() {
    int i = 0;
    printf("The equivalent postfix expression is: ");
    while (postfix[i]) {
        printf("%c", postfix[i++]);
    }
    printf("\n");
}

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return; // indicates end of function
    }
    stack[++top] = c;
}

char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}
