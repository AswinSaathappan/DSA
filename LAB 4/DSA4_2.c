#include <stdio.h>
#include <stdlib.h>

// Define the structure for the doubly linked list node
struct node {
    int info;
    struct node *prev;
    struct node *next;
};

// Global pointers for head and other temporary nodes
struct node *p, *head, *old, *n, *s;

// Function declarations
void traverse();
void traversereverse();
void insertbegin();
void insertmiddle();
void insertend();
void deletebegin();
void deletemiddle();
void deleteend();
void count();

int main() {
    head = NULL;
        printf("\nMenu:");
        printf("\n1. Create Linked List");
        printf("\n2. Traverse");
        printf("\n3. Insert at Beginning");
        printf("\n4. Insert in Middle");
        printf("\n5. Insert at End");
        printf("\n6. Delete from Beginning");
        printf("\n7. Delete from Middle");
        printf("\n8. Delete from End");
        printf("\n9. Count Nodes");
        printf("\n10. Traverse Reverse");
        printf("\n11. Exit");
    while (1) {
        printf("\nEnter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int i, numNodes;
                printf("Enter the number of nodes: ");
                scanf("%d", &numNodes);

                if (numNodes <= 0) {
                    printf("Number of nodes must be positive!\n");
                    break;
                }

                printf("Enter values: ");
                head = (struct node *)malloc(sizeof(struct node));
                scanf("%d", &head->info);
                head->next = NULL;
                head->prev = NULL;
                old = head;

                for (i = 1; i < numNodes; i++) {
                    n = (struct node *)malloc(sizeof(struct node));
                    scanf("%d", &n->info);
                    n->next = NULL;
                    n->prev = old;
                    old->next = n;
                    old = n;
                }
                break;
            }

            case 2:
                traverse();
                break;

            case 3:
                insertbegin();
                break;

            case 4:
                insertmiddle();
                break;

            case 5:
                insertend();
                break;

            case 6:
                deletebegin();
                break;

            case 7:
                deletemiddle();
                break;

            case 8:
                deleteend();
                break;

            case 9:
                count();
                break;

            case 10:
                traversereverse();  // Call the traversereverse function
                break;

            case 11:
                exit(0);

            default:
                printf("Invalid choice! Please choose a valid option.\n");
        }
    }
    return 0;
}

// Function to traverse and print the list from the beginning
void traverse() {
    p = head;
    printf("\nTHE LIST IS:\n");
    while (p != NULL) {
        printf("%d <-> ", p->info);
        p = p->next;
    }
    printf("NULL\n");
}

// Function to traverse and print the list in reverse
void traversereverse() {
    p = head;
    if (p == NULL) {
        printf("\nTHE LIST IS EMPTY\n");
        return;
    }
    // Traverse to the last node
    while (p->next != NULL) {
        p = p->next;
    }
    printf("\nTHE LIST IN REVERSE IS:\n");
    // Traverse backwards
    while (p != NULL) {
        printf("%d <-> ", p->info);
        p = p->prev;
    }
    printf("NULL\n");
}

// Function to insert a node at the beginning
void insertbegin() {
    int ele;
    printf("Enter element: ");
    scanf("%d", &ele);
    n = (struct node *)malloc(sizeof(struct node));
    n->info = ele;
    n->next = head;
    n->prev = NULL;
    if (head != NULL) {
        head->prev = n;
    }
    head = n;
    traverse();
}

// Function to insert a node in the middle
void insertmiddle() {
    int i, pos, ele;
    printf("Enter position and element: ");
    scanf("%d %d", &pos, &ele);

    if (pos <= 1) {
        insertbegin();
        return;
    }

    p = head;
    for (i = 1; i < pos - 1 && p != NULL; i++) {
        p = p->next;
    }

    if (p == NULL) {
        printf("Position out of bounds!\n");
        return;
    }

    n = (struct node *)malloc(sizeof(struct node));
    n->info = ele;
    n->next = p->next;
    n->prev = p;

    if (p->next != NULL) {
        p->next->prev = n;
    }
    p->next = n;

    traverse();
}

// Function to insert a node at the end
void insertend() {
    int ele;
    printf("Enter element: ");
    scanf("%d", &ele);
    n = (struct node *)malloc(sizeof(struct node));
    n->info = ele;
    n->next = NULL;

    if (head == NULL) {
        n->prev = NULL;
        head = n;
    } else {
        p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = n;
        n->prev = p;
    }
    traverse();
}

// Function to delete a node from the beginning
void deletebegin() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    p = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(p);
    traverse();
}

// Function to delete a node from the middle
void deletemiddle() {
    int i, pos;
    printf("Enter the position: ");
    scanf("%d", &pos);

    if (pos <= 1) {
        deletebegin();
        return;
    }

    p = head;
    for (i = 1; i < pos && p != NULL; i++) {
        p = p->next;
    }

    if (p == NULL) {
        printf("Position out of bounds!\n");
        return;
    }

    s = p->next;
    p->prev->next = s;
    if (s != NULL) {
        s->prev = p->prev;
    }
    free(p);
    traverse();
}

// Function to delete a node from the end
void deleteend() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    p = head;
    while (p->next != NULL) {
        old = p;
        p = p->next;
    }

    if (p == head) { // Only one node in the list
        head = NULL;
    } else {
        old->next = NULL;
    }
    free(p);
    traverse();
}

// Function to count the nodes in the list
void count() {
    int count = 0;
    p = head;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    printf("Total number of nodes: %d\n", count);
}
