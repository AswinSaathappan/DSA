#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to represent a Priority Queue
struct PriorityQueue {
    int heap[MAX]; // Array to store the heap
    int size; // Number of elements in the heap
};

// Function to initialize the priority queue
void initialize(struct PriorityQueue *pq) {
    pq->size = 0;
}

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to insert an element into the priority queue (Max-Heap)
void insert(struct PriorityQueue *pq, int element) {
    if (pq->size == MAX) {
        printf("Priority Queue is full!\n");
        return;
    }
    
    // Insert the new element at the end of the heap
    pq->heap[pq->size] = element;
    pq->size++;
    
    // Perform heapify-up operation
    int i = pq->size - 1;
    while (i > 0 && pq->heap[(i - 1) / 2] < pq->heap[i]) {
        swap(&pq->heap[(i - 1) / 2], &pq->heap[i]);
        i = (i - 1) / 2;
    }
    
    printf("%d inserted into the priority queue.\n", element);
}

// Function to heapify-down after deletion
void heapifyDown(struct PriorityQueue *pq, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    // Find the largest among root, left child, and right child
    if (left < pq->size && pq->heap[left] > pq->heap[largest])
        largest = left;
    
    if (right < pq->size && pq->heap[right] > pq->heap[largest])
        largest = right;
    
    // If the largest is not the root, swap and continue heapifying
    if (largest != i) {
        swap(&pq->heap[i], &pq->heap[largest]);
        heapifyDown(pq, largest);
    }
}

// Function to delete the maximum element from the priority queue
int extractMax(struct PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty!\n");
        return -1;
    }
    
    // Get the maximum element (root of the heap)
    int maxElement = pq->heap[0];
    
    // Replace the root with the last element and reduce the size
    pq->heap[0] = pq->heap[pq->size - 1];
    pq->size--;
    
    // Perform heapify-down to restore the heap property
    heapifyDown(pq, 0);
    
    printf("Maximum element %d extracted from the priority queue.\n", maxElement);
    return maxElement;
}

// Function to display the priority queue (heap)
void display(struct PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty!\n");
        return;
    }
    
    printf("Priority Queue (Max-Heap): ");
    for (int i = 0; i < pq->size; i++) {
        printf("%d ", pq->heap[i]);
    }
    printf("\n");
}

// Main function
int main() {
    struct PriorityQueue pq;
    initialize(&pq);
    
    insert(&pq, 10);
    insert(&pq, 40);
    insert(&pq, 20);
    insert(&pq, 50);
    insert(&pq, 30);
    
    display(&pq);
    
    extractMax(&pq);
    display(&pq);
    
    extractMax(&pq);
    display(&pq);
    
    return 0;
}

