#include <stdio.h>

int main() {
    int n;
    int j,i;
    int space;
    // Step 1: Get the number of rows from the user
    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &n);

    // Step 2: Loop through each row
    for (i = 0; i < n; i++)
	 {
        int number = 1; // Initialize the first number in the row

        // Step 3: Print leading spaces for alignment
        for (space = 0; space < n - i - 1; space++)
		 {
            printf(" ");
        }

        // Step 4: Loop to calculate and print each number in the row
        for (j = 0; j <= i; j++) 
		{
            printf("%d ", number); // Print the current number
            number = number * (i - j) / (j + 1); // Calculate the next number in the row
        }

        printf("\n"); // Move to the next row
    }

    return 0;
}

