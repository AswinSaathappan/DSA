#include <stdio.h>

int linearSearch(int arr[], int n, int target) {
int i;
    for ( i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target;
    printf("Enter the target element to search: ");
    scanf("%d", &target);

    int result = linearSearch(arr, n, target);

    if (result != -1) {
        printf("Element %d found at position %d\n", target, result+1);
    } else {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}
