#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the structure for a stack node
struct Node {
    int data;
    struct Node* next;
};

// Pointer to the top of the stack
struct Node* top = NULL;

// Function to check if the stack is empty
int isEmpty() {
    return top == NULL;
}

// Function to push an element onto the stack
void push(int data) {
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Stack overflow\n");
        exit(1);
    }
    // Initialize the new node and update the top pointer
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}

// Function to pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1;
    } else {
        struct Node* temp = top;
        int poppedData = top->data;
        top = top->next;
        free(temp);
        return poppedData;
    }
}

// Main function to evaluate a postfix expression using the linked list stack
int main() {
   	char str[50];
    printf("Enter a postfix expression (e.g., 231*+9-): ");
    scanf("%s", str);
    int i, num1, num2;
    int n = strlen(str);

    for (i = 0; i < n; i++) {
        // Check if the character is a digit
        if (isdigit(str[i])) {
            // Push the numeric value onto the stack
            push(str[i] - '0');
        } else {
            // Pop two operands for the operator
            num2 = pop();
			num1 = pop();
            // Perform the operation based on the operator
            switch (str[i]) {
                case '+':
                    push(num1 + num2);
                    break;
                case '-':
                    push(num1 - num2); 
                    break;
                case '*':
                    push(num1 * num2);
                    break;
                case '/':
                    push(num1 / num2); 
                    break;
            }
        }
    }

    // The final result is the only element left in the stack
    printf("Evaluated answer: %d\n", pop());
    return 0;
}

