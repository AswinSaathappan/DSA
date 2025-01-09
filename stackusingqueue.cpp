#include <stdio.h>
#define SIZE 6

int q1[SIZE], q2[SIZE];
int front1 = -1, rear1 = -1;
int front2 = -1, rear2 = -1;

// Check if Queue 1 is empty
int isEmpty1() {
    return (front1 == -1 || front1 > rear1);
}

// Check if Queue 1 is full
int isFull1() {
    return (rear1 == SIZE - 1);
}

// Enqueue into Queue 1
void enqueue1(int item) {
    if (isFull1()) {
        printf("Queue 1 is full\n");
    } else {
        if (front1 == -1) front1 = 0;
        q1[++rear1] = item;
    }
}

// Dequeue from Queue 1
int dequeue1() {
    if (isEmpty1()) {
        printf("Queue 1 is empty\n");
        return -1;
    } else {
        return q1[front1++];
    }
}

// Check if Queue 2 is empty
int isEmpty2() {
    return (front2 == -1 || front2 > rear2);
}

// Check if Queue 2 is full
int isFull2() {
    return (rear2 == SIZE - 1);
}

// Enqueue into Queue 2
void enqueue2(int item) {
    if (isFull2()) {
        printf("Queue 2 is full\n");
    } else {
        if (front2 == -1) front2 = 0;
        q2[++rear2] = item;
    }
}

// Dequeue from Queue 2
int dequeue2() {
    if (isEmpty2()) {
        printf("Queue 2 is empty\n");
        return -1;
    } else {
        return q2[front2++];
    }
}

// Manually swap the contents of q1 and q2
void swapQueues() {
    int tempArr[SIZE];
    int tempFront, tempRear;

    // Copy q1 to tempArr
    for (int i = 0; i <= rear1; i++) {
        tempArr[i] = q1[i];
    }
    tempFront = front1;
    tempRear = rear1;

    // Copy q2 to q1
    for (int i = 0; i <= rear2; i++) {
        q1[i] = q2[i];
    }
    front1 = front2;
    rear1 = rear2;

    // Copy tempArr to q2
    for (int i = 0; i <= tempRear; i++) {
        q2[i] = tempArr[i];
    }
    front2 = tempFront;
    rear2 = tempRear;
}

// Push operation: Adds element to stack
void push(int item) {
    // Enqueue item into q2
    enqueue2(item);

    // Transfer all elements from q1 to q2
    while (!isEmpty1()) {
        enqueue2(dequeue1());
    }

    // Swap the contents of q1 and q2
    swapQueues();

    printf("%d pushed to stack\n", item);
}

// Pop operation: Removes top element from stack
void pop() {
    if (isEmpty1()) {
        printf("Stack is empty. Cannot pop\n");
    } else {
        int item = dequeue1();
        printf("Popped item: %d\n", item);
    }
}

// Display elements of the stack
void display() {
    if (isEmpty1()) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = front1; i <= rear1; i++) {
            printf("%d ", q1[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, item;

    do {
        printf("\nStack Operations using Two Queues:");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display Stack");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to push: ");
                scanf("%d", &item);
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

