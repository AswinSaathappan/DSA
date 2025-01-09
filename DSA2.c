#include <stdio.h>

int main() {
    int arr[10];
    int i,j;

    // Step 3: Input 10 elements into the array
    for (i = 0; i < 10; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Step 4: Print elements horizontally
    printf("\nHorizontal:\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Step 5: Print elements vertically
    printf("\nVertical:\n");
    for (i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }

    // Step 6: Print elements diagonally
    printf("\nDiagonal:\n");
    for (i = 0; i < 10; i++) {
        // Print leading spaces
        for (j = 0; j < i; j++) {
            printf("  ");
        }
        printf("%d\n", arr[i]);
    }

    return 0;
}

