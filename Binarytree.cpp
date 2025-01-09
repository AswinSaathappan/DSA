#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* right;
    struct node* left;
};

struct node* create() { 
    struct node* n = (struct node*)malloc(sizeof(struct node));
    int ele;
    printf("Enter the element (-1 for no node): ");
    scanf("%d", &ele);
    if (ele == -1) {
        return 0; // No node to be created
    }
    n->data = ele;
    printf("Enter left child of %d\n", ele);
    n->left = create(); // Recursively create the left subtree
    printf("Enter right child of %d\n", ele);
    n->right = create(); // Recursively create the right subtree
    return n; 
}

void Preorder(struct node* root) {
    if (root == 0) {
        return;
    }
    printf("%d ", root->data);         // Visit the root
    Preorder(root->left);              // Visit the left subtree
    Preorder(root->right);             // Visit the right subtree
}

void Inorder(struct node* root) {
    if (root == 0) {
        return;
    }
    Inorder(root->left);               // Visit the left subtree
    printf("%d ", root->data);         // Visit the root
    Inorder(root->right);              // Visit the right subtree
}

void Postorder(struct node* root) {
    if (root == 0) {
        return;
    }
    Postorder(root->left);             // Visit the left subtree
    Postorder(root->right);            // Visit the right subtree
    printf("%d ", root->data);         // Visit the root
}

int main() {
    struct node* root = create();      // Create the tree
    printf("\nPreorder traversal: ");
    Preorder(root);                    // Preorder traversal
    printf("\nInorder traversal: ");
    Inorder(root);                     // Inorder traversal
    printf("\nPostorder traversal: ");
    Postorder(root);                   // Postorder traversal
    return 0;
}

