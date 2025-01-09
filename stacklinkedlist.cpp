#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;

int isempty() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return 1;
    } else {
        return 0;
    }
}

void peek() {
    if (!isempty()) {
        printf("The top element is %d\n", top->data);
    }
}

void peep() {
    struct node* p = top;
    if (isempty()) {
        printf("Stack is empty\n");
    } else {
        printf("Stack elements: ");
        while (p != NULL) {
            printf("%d -> ", p->data);
            p = p->next;
        }
        printf("NULL\n");
    }
}

void push() {
    int ele;
    printf("\nEnter data: ");
    scanf("%d", &ele);

    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->data = ele;
    p->next = NULL;
    if(top==NULL)
    {
     top = p;
    }
    else
    {
    	p->next=top;
    	top=p;
	}
}

void pop() {
    if (isempty()) {
        printf("Stack underflow, cannot pop\n");
    } else {
        struct node* p = top;
        printf("Element %d is deleted\n", p->data);
        top = top->next;
        free(p);
    }
}

int main() {
    int choice;
    do {
        printf("\n\nStack Operations:");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Peep");
        printf("\n5. Check if Empty");
        printf("\n6. Exit");
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
                isempty();
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

