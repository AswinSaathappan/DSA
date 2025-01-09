#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the BST
struct node {
    int data;  // Data of the node
    struct node *left_child;  // Pointer to the left child
    struct node *right_child; // Pointer to the right child
};

// Function to create a new node
struct node* new_node(int x) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));  // Allocate memory for new node
    temp->data = x;  // Set the node's data
    temp->left_child = NULL;  // Initialize left child as NULL
    temp->right_child = NULL; // Initialize right child as NULL
    return temp;  // Return the new node
}

// Function to search for a value in the BST
struct node* search(struct node *root, int x) {
    if (root == NULL || root->data == x)  // If root is NULL or data is found
        return root;  // Return the node
    else if (x > root->data)  // If the value is greater, search in the right subtree
        return search(root->right_child, x);
    else  // Otherwise, search in the left subtree
        return search(root->left_child, x);
}

// Function to insert a new node into the BST
struct node* insert(struct node *root, int x) {
    if (root == NULL)  // If the tree is empty, create a new node
        return new_node(x);
    else if (x > root->data)  // If the value is greater, insert in the right subtree
        root->right_child = insert(root->right_child, x);
    else  // Otherwise, insert in the left subtree
        root->left_child = insert(root->left_child, x);
    return root;  // Return the updated root
}

// Function to find the minimum node in the BST
struct node* find_minimum(struct node *root) {
    if (root == NULL)  // If the tree is empty, return NULL
        return NULL;
    else if (root->left_child != NULL)  // Keep going left to find the minimum
        return find_minimum(root->left_child);
    return root;  // Return the leftmost node
}

// Function to delete a node from the BST
struct node* Delete(struct node *root, int x) {
    if (root == NULL)  // If the tree is empty, return NULL
        return NULL;
    if (x > root->data)  // If the value is greater, go to the right subtree
        root->right_child = Delete(root->right_child, x);
    else if (x < root->data)  // If the value is smaller, go to the left subtree
        root->left_child = Delete(root->left_child, x);
    else {  // Node with the value found
        // Case 1: Node with no children
        if (root->left_child == NULL && root->right_child == NULL){
            free(root);  // Free the node
            return NULL;  // Return NULL to the parent node
        }
        // Case 2: Node with one child
        else if (root->left_child == NULL || root->right_child == NULL){
            struct node *temp;
            if (root->left_child == NULL)  // If the left child is NULL
                temp = root->right_child;  // Set temp to the right child
            else  // Otherwise
                temp = root->left_child;  // Set temp to the left child
            free(root);  // Free the node
            return temp;  // Return the child node to the parent node
        }
        // Case 3: Node with two children
        else {
            struct node *temp = find_minimum(root->right_child);  // Find the in-order successor
            root->data = temp->data;  // Replace data with the in-order successor's data
            root->right_child = Delete(root->right_child, temp->data);  // Delete the in-order successor
        }
    }
    return root;  // Return the updated root
}

// Function for in-order traversal of the BST
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left_child);  // Visit left subtree
        printf(" %d ", root->data);  // Print the data
        inorder(root->right_child);  // Visit right subtree
    }
}

int main() {
    struct node *root;
    root = new_node(20);  // Create root node with value 20
    insert(root, 5);  // Insert values into the BST
    insert(root, 1);
    insert(root, 15);
    insert(root, 9);
    insert(root, 7);
    insert(root, 12);
    insert(root, 30);
    insert(root, 25);
    insert(root, 40);
    insert(root, 45);
    insert(root, 42);

    printf("In-order traversal before deletion:\n");
    inorder(root);  // Print in-order traversal
    printf("\n");

    root = Delete(root, 1);  // Delete node with value 1
    root = Delete(root, 40);  // Delete node with value 40
    root = Delete(root, 45);  // Delete node with value 45
    root = Delete(root, 9);   // Delete node with value 9

    printf("In-order traversal after deletion:\n");
    inorder(root);  // Print in-order traversal after deletions
    printf("\n");

    return 0;
}

