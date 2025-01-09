#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
} *front = NULL, *rear = NULL, *p;

int empty() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return 1;
    } else {
        return 0;
    }
}

void display() {
    if (empty()) {
        return;
    } else {
        p = front;
        printf("Queue: ");
        do {
            printf("%d -> ", p->data);
            p = p->next;
        } while (p != front); // Stop when we come back to the front
        printf("FRONT\n");
    }
}

void enqueue() {
    p = (struct node*)malloc(sizeof(struct node));
    if (p == NULL) {
        printf("Memory allocation failed! Cannot enqueue.\n");
        return;
    }
    printf("Enter the data: ");
    scanf("%d", &p->data);
    p->next = NULL;

    if (front == NULL) {
        front = rear = p;
        rear->next = front;  // Circular link
    } else {
        rear->next = p;
        rear = p;
        rear->next = front;  // Maintain circular link
    }

    display();
}

void dequeue() {
    if (empty()) {
        return;
    } else {
        p = front;
        printf("Deleted element is %d\n", p->data);
        if (front == rear) {
            // Only one element was in the queue
            front = rear = NULL;
        } else {
            front = front->next;
            rear->next = front;  // Maintain circular link
            p->next = NULL;  // Avoid dangling pointer
            free(p);
        }
        
    }

    display();
}

int main() {
    int choice;
    do {
        printf("\nQueue Operations:");
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Check if Empty");
        printf("\n5. Exit");
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
                empty();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

