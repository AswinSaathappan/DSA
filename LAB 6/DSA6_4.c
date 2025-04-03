#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char stack[MAX];
char infix[MAX];
char prefix[MAX];
int top = -1;

void push(char);
char pop();
int isEmpty();
void inToPre();
int space(char);
void print();
int precedence(char);
void reverse(char*);

int main() {
    printf("Enter the infix expression: ");
    gets(infix);
    inToPre();
    print();
    return 0;
}

void inToPre() {
    // Reverse the infix expression
    reverse(infix);

    int i, j = 0;
    char next;
    char symbol;

    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];
        // if symbol is not a whitespace
        if (!space(symbol)) {
            switch (symbol) {
                case ')':
                    push(symbol);
                    break;

                case '(':
                    // Pop until ')' is found
                    while ((next = pop()) != ')') {
                        prefix[j++] = next;
                    }
                    break;

                case '+':
                case '-':
                case '*':
                case '/':
                case '^':
                    // Pop all operators from the stack with higher or equal precedence
                    while (!isEmpty() && precedence(stack[top]) > precedence(symbol) && stack[top] != ')') {
                        prefix[j++] = pop();
                    }
                    push(symbol);
                    break;

                default: // if the symbol is an operand
                    prefix[j++] = symbol;
            }
        }
    }
    // Pop all remaining operators in the stack
    while (!isEmpty()) {
        prefix[j++] = pop();
    }
    prefix[j] = '\0'; // Ensure null-termination of the prefix string

    // Reverse the prefix expression to get the final result
    reverse(prefix);
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
            return 0; // This case covers ')' and other non-operator characters
    }
}

void reverse(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void print() {
    printf("The equivalent prefix expression is: %s\n", prefix);
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
