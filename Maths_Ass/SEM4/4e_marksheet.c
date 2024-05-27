#include <stdio.h>
#define NUM_SUBJECTS 5
int main() {
    char name[50];
    int marks[NUM_SUBJECTS];
    float total = 0;  
    printf("Enter student name: ");
    scanf("%s", name);
    printf("Enter marks for each subject:\n");
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        printf("Subject %d: ", i + 1);
        scanf("%d", &marks[i]);
        total += marks[i];
    }
    float percentage = (total / (NUM_SUBJECTS * 100)) * 100;
    printf("\nStudent Name: %s\n", name);
    printf("Marks Obtained:\n");
    for (int i = 0; i < NUM_SUBJECTS; i++) {
        printf("Subject %d: %d\n", i + 1, marks[i]);
    }
    printf("Total Marks: %.2f/500\n", total);
    printf("Percentage: %.2f%%\n", percentage);
    
    if (percentage >= 90) {
        printf("Grade: A\n");
    } else if (percentage >= 80) {
        printf("Grade: B\n");
    } else if (percentage >= 70) {
        printf("Grade: C\n");
    } else if (percentage >= 60) {
        printf("Grade: D\n");
    } else if (percentage >= 50) {
        printf("Grade: E\n");
    } else {
        printf("Grade: F\n");
    }

    return 0;
}
