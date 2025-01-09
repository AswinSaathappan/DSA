#include <stdio.h>
#define MAX 4

int stack1[MAX];  // Primary stack for storing elements
int stack2[MAX];  // Auxiliary stack for transferring elements
int top1 = -1;    // Top pointer for stack1
int top2 = -1;    // Top pointer for stack2

// Stack operations for stack1
void push1(int ele) {
    if (top1 >= MAX - 1) {
        printf("\nStack1 is full. Push is not possible");
    } else {
        stack1[++top1] = ele;
    }
}

int pop1() {
    if (top1 == -1) {
        printf("\nStack1 is empty. Pop is not possible");
        return -1;
    } else {
        return stack1[top1--];
    }
}

// Stack operations for stack2
void push2(int ele) {
    if (top2 >= MAX - 1) {
        printf("\nStack2 is full. Push is not possible");
    } else {
        stack2[++top2] = ele;
    }
}

int pop2() {
    if (top2 == -1) {
        printf("\nStack2 is empty. Pop is not possible");
        return -1;
    } else {
        return stack2[top2--];
    }
}

// Enqueue operation: Inserts element by transferring elements between stacks
void enqueue(int x) {
    // Transfer all elements from stack1 to stack2
    while (top1 != -1) {
        push2(pop1());
    }

    // Push the new element into stack1
    push1(x);
    printf("\nEnqueued %d to the queue", x);

    // Transfer all elements back from stack2 to stack1
    while (top2 != -1) {
        push1(pop2());
    }
}

// Dequeue operation: Removes the front element
void dequeue() {
    if (top1 == -1) {
        printf("\nQueue is empty. Dequeue is not possible");
    } else {
        printf("\nDequeued %d from the queue", pop1());
    }
}

// Display elements of the queue
void displayQueue() {
    if (top1 == -1) {
        printf("\nQueue is empty");
    } else {
        printf("\nQueue elements: ");
        for (int i = top1; i >= 0; i--) {
            printf("%d ", stack1[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, ele;
    do {
        printf("\n\nQueue Operations using Two Stacks:");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display Queue");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the element to be enqueued: ");
                scanf("%d", &ele);
                enqueue(ele);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.");
        }
    } while (choice != 4);

    return 0;
}

