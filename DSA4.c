#include <stdio.h>

int main() {
    int num, reversed = 0, remainder;

    // Step 2: Input the number
    printf("Enter a number: ");
    scanf("%d", &num);

    // Step 4: Reverse the number
    while (num != 0) {
        remainder = num % 10;           // Extract the last digit
        reversed = reversed * 10 + remainder;  // Append the digit to reversed
        num /= 10;                      // Remove the last digit
    }

    // Step 5: Output the reversed number
    printf("Reversed number: %d\n", reversed);

    return 0;
}

