#include <stdio.h>

int main() {
    int num, reversed = 0, remainder;

    // Step 2: Input the number
    printf("Enter a number: ");
    scanf("%d", &num);

    // Step 3: Handle negative numbers
    if (num < 0) {
        num = -num;
    }

    // Step 4: Reverse the number
    int originalNum = num;  // Save the original number for later use
    while (num != 0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }

    // Step 5: Print the individual digits
    printf("The individual digits are:\n");
    while (reversed != 0) {
        remainder = reversed % 10;
        printf("%d\n", remainder);
        reversed /= 10;
    }

    return 0;
}

