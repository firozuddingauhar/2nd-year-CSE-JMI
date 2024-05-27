#include <stdio.h>

int main() {
    int arr[10];
    int n, sum = 0, evenSum = 0, oddSum = 0, max, min, secondLargest, secondSmallest;

    // take array elements from the user
    printf("Enter 10 integers:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    // Calculate the sum of the array elements
    for (int i = 0; i < 10; i++) {
        sum += arr[i];
    }
    printf("Sum of array elements: %d\n\n", sum);

    // Calculate the average
    float average = (float)sum / 10;
    printf("Average of array elements: %.2f\n\n", average);

    // Calculate the sum of even and odd numbers
    for (int i = 0; i < 10; i++) {
        if (arr[i] % 2 == 0) {
            evenSum += arr[i];
        } else {
            oddSum += arr[i];
        }
    }
    printf("Sum of even numbers: %d\n\n", evenSum);
    printf("Sum of odd numbers: %d\n\n", oddSum);


    // Find the greatest number
    max = arr[0];
    for (int i = 1; i < 10; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Greatest number: %d\n\n", max);

    // Find the smallest number
    min = arr[0];
    for (int i = 1; i < 10; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    printf("Smallest number: %d\n\n", min);

    // Display elements in reverse order
    printf("Elements in reverse order:");
    for (int i = 9; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // Copy elements from the source array to the copy array
    int copyArray[10];
    for (int i = 0; i < 10; i++) {
        copyArray[i] = arr[i];
    }
    printf("Elements in the copy array:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", copyArray[i]);
    }
    printf("\n\n");

    // Sort the array in ascending order (Bubble Sort)
    for (int i = 0; i < 10 - 1; i++) {
        for (int j = 0; j < 10 - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Sorted array in ascending order: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // Find the second largest
    secondLargest = arr[8];
    printf("Second largest number: %d\n\n", secondLargest);

    // Find the second smallest
    secondSmallest = arr[1];
    printf("Second smallest number: %d\n\n", secondSmallest);

    return 0;
}
