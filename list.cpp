#include<stdio.h>
#include<stdlib.h>

struct node{
	int info;
	struct node* next;
};

struct node *p, *head, *old, *n, *s;

void traverse();
void insertbegin();
void insertmiddle();
void insertend();
void count();
void deletebegin();
void deletemiddle();
void deleteend();

int main() {
    int choice;
    head = NULL;

    while(1) {
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
        printf("\n10. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if (head != NULL) {
                    printf("\nLinked list already created!");
                    break;
                }
                int num;
                printf("Enter number of nodes: ");
                scanf("%d", &num);
                printf("Enter the linked list elements: ");
                
                head = (struct node*)malloc(sizeof(struct node));
                scanf("%d", &head->info);
                head->next = NULL;
                old = head;

                for(int i = 1; i < num; i++) {
                    n = (struct node*)malloc(sizeof(struct node));
                    scanf("%d", &n->info);
                    n->next = NULL;
                    old->next = n;
                    old = n;
                }
                traverse();
                break;
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
                exit(0);
            default:
                printf("Invalid choice! Please choose a valid option.");
        }
    }

    return 0;
}

void traverse() {
    if (head == NULL) {
        printf("\nThe list is empty.\n");
        return;
    }
    
    p = head;
    printf("\nTHE LIST IS\n");
    while(p != NULL) {
        printf("%d->", p->info);
        p = p->next;
    }
    printf("NULL\n");
}

void insertbegin() {
    int ele;
    printf("\nEnter the element: ");
    scanf("%d", &ele);
    n = (struct node*)malloc(sizeof(struct node));
    n->info = ele;
    n->next = head;
    head = n;
    traverse();
}

void insertmiddle() {
    if (head == NULL) {
        printf("\nThe list is empty. Insert elements at the beginning or end first.\n");
        return;
    }

    int pos, ele;
    printf("\nEnter position and element: ");
    scanf("%d %d", &pos, &ele);
    old = head;
    p = head;
    n = (struct node*)malloc(sizeof(struct node));
    n->info = ele;

    for(int i = 1; i < pos; i++) {
        old = p;
        p = p->next;
    }
    old->next = n;
    n->next = p;
    traverse();
}

void insertend() {
    int ele;
    printf("\nEnter element: ");
    scanf("%d", &ele);
    n = (struct node*)malloc(sizeof(struct node));
    n->info = ele;
    p = head;

    if (p == NULL) {
        head = n;
        n->next = NULL;
    } else {
        while(p->next != NULL) {
            p = p->next;
        }
        p->next = n;
        n->next = NULL;
    }
    traverse();
}

void count() {
    int c = 0;
    p = head;
    while(p != NULL) {
        c++;
        p = p->next;
    }
    printf("\nNumber of nodes: %d\n", c);
}

void deletebegin() {
    if (head == NULL) {
        printf("\nThe list is empty.\n");
        return;
    }

    p = head;
    head = head->next;
    free(p);
    traverse();
}

void deletemiddle() {
    if (head == NULL) {
        printf("\nThe list is empty.\n");
        return;
    }

    int pos;
    printf("\nEnter position to be deleted: ");
    scanf("%d", &pos);
    p = head;
    old = head;

    for(int i = 1; i < pos; i++) {
        old = p;
        p = p->next;
    }
    s = p->next;
    old->next = s;
    free(p);
    traverse();
}

void deleteend() {
    if (head == NULL) {
        printf("\nThe list is empty.\n");
        return;
    }

    p = head;
    old = head;

    while(p->next != NULL) {
        old = p;
        p = p->next;
    }
    old->next = NULL;
    free(p);
    traverse();
}

