
#include <stdio.h>
#include <stdlib.h>

// Define the structure of the Node
struct Node {
    int data;
    struct Node* leftChild;
    struct Node* rightChild;
    int height;
};

// Utility function to get the height of a node
int height(struct Node* node) {
    return (node == NULL) ? 0 : node->height;
}

// Utility function to calculate the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    newNode->height = 1; // New node is initially at height 1
    return newNode;
}

// Right rotate utility
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->leftChild;
    struct Node* T2 = x->rightChild;

    // Perform rotation
    x->rightChild = y;
    y->leftChild = T2;

    // Update heights
    y->height = max(height(y->leftChild), height(y->rightChild)) + 1;
    x->height = max(height(x->leftChild), height(x->rightChild)) + 1;

    // Return new root
    return x;
}

// Left rotate utility
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->rightChild;
    struct Node* T2 = y->leftChild;

    // Perform rotation
    y->leftChild = x;
    x->rightChild = T2;

    // Update heights
    x->height = max(height(x->leftChild), height(x->rightChild)) + 1;
    y->height = max(height(y->leftChild), height(y->rightChild)) + 1;

    // Return new root
    return y;
}

// Get the balance factor of a node
int getBalance(struct Node* node) {
    return (node == NULL) ? 0 : height(node->leftChild) - height(node->rightChild);
}

// Function to find the node with the smallest value
struct Node* findMinimum(struct Node* root) {
    if (root == NULL)  // If the tree is empty, return NULL
        return NULL;
    else if (root->leftChild != NULL)  // Keep going left to find the minimum
        return findMinimum(root->leftChild);
    return root;  // Return the leftmost node

}

// Function to insert a node into the AVL tree
struct Node* insert(struct Node* node, int data) {
    // Perform the normal BST insertion
    if (node == NULL)
        return createNode(data);

    if (data < node->data)
        node->leftChild = insert(node->leftChild, data);
    else if (data > node->data)
        node->rightChild = insert(node->rightChild, data);
    else // Equal keys are not allowed in BST
        return node;

    // Update the height of this ancestor node
    node->height = 1 + max(height(node->leftChild), height(node->rightChild));

    // Get the balance factor
    int balance = getBalance(node);

    // If the node becomes unbalanced, then perform rotations

    // Left Left Case
    if (balance > 1 && data < node->leftChild->data)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && data > node->rightChild->data)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && data > node->leftChild->data) {
        node->leftChild = leftRotate(node->leftChild);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && data < node->rightChild->data) {
        node->rightChild = rightRotate(node->rightChild);
        return leftRotate(node);
    }

    return node; // Return the (unchanged) node pointer
}

// Function to delete a node from the AVL tree
struct Node* Delete(struct Node* root, int data) {
    if (root == NULL) // Base case: the tree is empty
        return NULL;

    // Traverse to the correct node
    if (data < root->data)
        root->leftChild = Delete(root->leftChild, data);
    else if (data > root->data)
        root->rightChild = Delete(root->rightChild, data);
    else {
        // Node with the value found

        // Case 1: No children
        if (root->leftChild == NULL && root->rightChild == NULL) {
            free(root);
            return NULL;
        }
        // Case 2: One child
        
    else if (root->leftChild == NULL || root->rightChild == NULL) {
        struct Node* temp; // Change struct node* to struct Node*
        if (root->leftChild == NULL)  // If the left child is NULL
          temp = root->rightChild;  // Set temp to the right child
    else  // Otherwise
        temp = root->leftChild;  // Set temp to the left child
        
        free(root);  // Free the node
        return temp;  // Return the child node to the parent node
}

        // Case 3: Two children
        else {
            struct Node* temp = findMinimum(root->rightChild); // Find in-order successor
            root->data = temp->data;
            root->rightChild = Delete(root->rightChild, temp->data); // Delete the successor
        }
    }

    // Update the height of the current node
    root->height = 1 + max(height(root->leftChild), height(root->rightChild));

    // Get the balance factor
    int balance = getBalance(root);

    // Rebalance the tree if necessary

    // Left Left Case
    if (balance > 1 && getBalance(root->leftChild) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->leftChild) < 0) {
        root->leftChild = leftRotate(root->leftChild);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->rightChild) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->rightChild) > 0) {
        root->rightChild = rightRotate(root->rightChild);
        return leftRotate(root);
    }

    return root; // Return the (possibly rebalanced) root
}

// In-order traversal to print the tree
void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->leftChild);
        printf("%d ", root->data);
        inOrder(root->rightChild);
    }
}

// Driver code
int main() {
    struct Node* root = NULL;

    // Insert nodes into the AVL tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("In-order traversal of the AVL tree:\n");
    inOrder(root);
    printf("\n");

    // Delete nodes from the AVL tree
    root = Delete(root, 20);
    printf("In-order traversal after deleting 20:\n");
    inOrder(root);
    printf("\n");

    return 0;
}
