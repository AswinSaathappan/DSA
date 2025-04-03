#include<stdio.h>
#define MAX 4

int stack[MAX];
int top = -1;

int isfull() {
    if (top >= MAX - 1) {
        printf("\nStack is full");
        return 1;
    } else {
        return 0;
    }
}

int isempty() {
    if (top == -1) {
        printf("\nStack is empty");
        return 1;
    } else {
        return 0;
    }
}

int peek() {
    if (!isempty()) {
        printf("\nThe peek element is %d", stack[top]);
        return stack[top];
    }
    return -1;  // Return -1 if the stack is empty
}

void peep() {
    if (isempty()) {
        printf("\nStack is empty");
    } else {
        printf("\nStack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

void pop() {
    if (isempty()) {
        printf("\nStack is empty. Pop is not possible");
    } else {
        int n = stack[top];
        top--;
        printf("\nAfter pop: %d", n);
    }
}

void push() {
    if (isfull()) {
        printf("\nStack is full. Push is not possible");
    } else {
        int ele;
        printf("\nEnter the element to be pushed: ");
        scanf("%d", &ele);
        top++;
        stack[top] = ele;
    }
}

int main() {
        int choice;
        printf("\n\nStack Operations:");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Peep");
        printf("\n5. Check if Full");
        printf("\n6. Check if Empty");
        printf("\n7. Exit");
    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                peep();
                break;
            case 5:
                isfull();
                break;
            case 6:
                isempty();
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.");
        }
    } while (choice != 7);

    return 0;
}
