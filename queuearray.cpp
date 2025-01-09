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
        while (p != NULL) {
            printf("%d -> ", p->data);
            p = p->next;
        }
        printf("NULL\n");
    }
}

void enqueue() {
    p = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &p->data);
    p->next = NULL;

    if (front == NULL) {
        front = rear = p;
    } else {
        rear->next = p;
        rear = p;
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
            front = rear = NULL;
        } else {
            front = front->next;
            p->next=NULL;
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

