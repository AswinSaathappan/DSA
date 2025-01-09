#include <stdio.h>

int binarySearchRecursive(int a[], int start, int end, int target);

int main() {
    int a[10], target, n;
    printf("Enter the size of the array:");
    scanf("%d", &n);
    
    printf("Enter the elements in ascending order:");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    printf("Enter the element to be searched:");
    scanf("%d", &target);
    
    int result = binarySearchRecursive(a, 0, n - 1, target);
    
    if (result != -1) {
        printf("The element is found at position %d", result + 1);
    } else {
        printf("The number is not found");
    }

    return 0;
}

int binarySearchRecursive(int a[], int start, int end, int target) {
    if (start <= end) {
        int mid = (start + end) / 2;
    if (target == a[mid]) {
            return mid;
        } else if (target < a[mid]) {
            return binarySearchRecursive(a, start, mid - 1, target);
        } else {
            return binarySearchRecursive(a, mid + 1, end, target);
        }
    }

    return -1; // Element not found
}

