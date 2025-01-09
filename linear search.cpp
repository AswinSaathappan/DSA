#include <stdio.h>

int linearSearchRecursive(int arr[], int start, int end, int target) {
    if (start > end) {
        return -1;
    }

    if (arr[start] == target) {
        return start;
    }

    return linearSearchRecursive(arr, start + 1, end, target);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target;
    printf("Enter the target element to search: ");
    scanf("%d", &target);

    int result = linearSearchRecursive(arr, 0, n - 1, target);

    if (result != -1) {
        printf("Element %d found at position %d\n", target, result + 1);
    } else {
        printf("Element %d not found in the array\n", target);
    }
}
