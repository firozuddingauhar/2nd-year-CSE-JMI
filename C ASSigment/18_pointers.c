#include <stdio.h>
#include <string.h>

// Function to swap values of two integer variables
void swapIntegers(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to swap strings of two character arrays
void swapStrings(char* str1, char* str2) {
    char temp[100];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

// Function to sort an array of integers using pointers
void sort(int* ptr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (*(ptr + j) > *(ptr + j + 1)) {
                int temp = *(ptr + j);
                *(ptr + j) = *(ptr + j + 1);
                *(ptr + j + 1) = temp;
            }
        }
    }
}

// Function to find the maximum number between two numbers using a pointer
int findMax(int* a, int* b) {
    return (*a > *b) ? *a : *b;
}

// Function to calculate the length of a string using a pointer
int stringLength(const char* str) {
    const char* p = str;
    while (*p != '\0') {
        p++;
    }
    return p - str;
}

// Function to count the number of vowels and consonants in a string using a pointer
void countVowelsAndConsonants(const char* str, int* vowels, int* consonants) {
    *vowels = 0;
    *consonants = 0;
    while (*str) {
        char ch = *str;
        if (ch >= 'a' && ch <= 'z') {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                (*vowels)++;
            } else {
                (*consonants)++;
            }
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + 'a' - 'A';
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                (*vowels)++;
            } else {
                (*consonants)++;
            }
        }
        str++;
    }
}

// Function to compute the sum of all elements in an array using pointers
int sumArray(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(arr + i);
    }
    return sum;
}

// Function to print the elements of an array in reverse order using pointers
void printArrayInReverse(int* arr, int size) {
    for (int i = size - 1; i >= 0; i--) {
        printf("%d ", *(arr + i));
    }
    printf("\n\n");
}

// Function to print a string in reverse using a pointer
void printStringInReverse(const char* str) {
    const char* p = str;
    while (*p != '\0') {
        p++;
    }
    p--;
    while (p >= str) {
        printf("%c", *p);
        p--;
    }
    printf("\n");
}

int main() {
    int num1 , num2 ;
    char str1[100], str2[100];
    int array[] = {4, 1, 8, 3, 6, 7};
    char inputStr[100];
    int vowels, consonants;

    // Swap integers
    printf("Enter num1 and num2");
    scanf("%d %d",&num1 , &num2);
    printf("Before swapping integers: num1=%d, num2=%d\n", num1, num2);
    swapIntegers(&num1, &num2);
    printf("After swapping integers: num1=%d, num2=%d\n\n", num1, num2);

    // Swap strings
    printf("Enter two strings: ");
    scanf("%s %s", str1, str2);
    printf("Before swapping strings: str1=%s, str2=%s\n", str1, str2);
    swapStrings(str1, str2);
    printf("After swapping strings: str1=%s, str2=%s\n\n", str1, str2);

    // Sort the array
    int size = sizeof(array) / sizeof(array[0]);
    sort(array, size);
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n\n");

    // Find the maximum number between two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    int max = findMax(&num1, &num2);
    printf("The maximum number is: %d\n\n", max);

    // Calculate the length of a string
    printf("Enter a string: ");
    scanf("%s", inputStr);
    int length = stringLength(inputStr);
    printf("Length of the string: %d\n\n", length);

    // Count vowels and consonants in a string
    printf("Enter a string: ");
    scanf("%s", inputStr);
    countVowelsAndConsonants(inputStr, &vowels, &consonants);
    printf("Vowels: %d, Consonants: %d\n\n", vowels, consonants);

    // Compute the sum of elements in an array
    int sum = sumArray(array, size);
    printf("Sum of array elements: %d\n\n", sum);

    // Print the array in reverse order
    printf("Array in reverse order: ");
    printArrayInReverse(array, size);

    // Print a string in reverse
    printf("Enter a string: ");
    scanf("%s", inputStr);
    printf("String in reverse: ");
    printStringInReverse(inputStr);

    return 0;
}
