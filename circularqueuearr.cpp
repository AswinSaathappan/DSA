#include <stdio.h>
#define SIZE 6

int queue[SIZE];
int front = -1;
int rear = -1;

int qfull() {
    if ((rear + 1) % SIZE == front) {
        printf("Queue is full\n");
        return 1;
    } else {
        return 0;
    }
}

int qempty() {
    if (front == -1) {
        printf("Queue is empty\n");
        return 1;
    } else {
        return 0;
    }
}

void enqueue() {
    if (qfull()) {
        printf("Cannot enqueue, queue is full\n");
    } else {
        int item;
        printf("Enter item: ");
        scanf("%d", &item);
        if (front == -1) {
            front = 0; // Set front to 0 when first element is enqueued
        }
        rear = (rear + 1) % SIZE; // Wrap around using modulo operation
        queue[rear] = item;
        printf("%d enqueued\n", item);
    }
}

void dequeue() {
    if (qempty()) {
        printf("Cannot dequeue, queue is empty\n");
    } else {
        int item = queue[front];
        printf("Dequeued item is %d\n", item);
        if (front == rear) {
            // Reset front and rear if the queue becomes empty after dequeue
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE; // Wrap around using modulo operation
        }
    }
}

void display() {
    if (qempty()) {
        printf("Queue is empty, nothing to display\n");
    } else {
        printf("Queue elements are: ");
        int i = front;//while front doesn't reach to rear scan the elements and print them
        while (i!=rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % SIZE; // Wrap around using modulo operation
        }
        printf("%d",queue[i]);
    }
}

int main() {
    int choice;
    do {
        printf("\nQueue Operations:");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Check if Full");
        printf("\n5. Check if Empty");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                qfull();
                break;
            case 5:
                qempty();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);

    return 0;
}

