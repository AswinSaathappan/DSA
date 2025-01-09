#include <stdio.h>

int main() {
    int marks[5];
    int sum = 0,i,j;
    float average;
    int rank[5];
    
    // Step 4: Input marks for each student
    for (i = 0; i < 5; i++) {
        printf("Enter marks for student %d: ", i + 1);
        scanf("%d", &marks[i]);
        sum += marks[i];
    }

    // Step 5: Calculate average
    average = sum / 5.0;

    // Step 6: Determine ranks
    for (i = 0; i < 5; i++) {
        rank[i] = 1; // Start with rank 1 for each student
        for (j = 0; j < 5; j++) {
            if (marks[j] > marks[i]) {
                rank[i]++;
            }
        }
    }

    // Step 7: Display results
    printf("\nAverage Marks: %.2f\n", average);
    for (i = 0; i < 5; i++) {
        printf("Student %d: Marks = %d, Rank = %d\n", i + 1, marks[i], rank[i]);
    }

    return 0;
}

