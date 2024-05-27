#include <stdio.h>
#include <string.h>
#include <ctype.h>

int countSpaces(const char *text) {
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ') {
            count++;
        }
    }
    return count;
}

int countTabs(const char *text) {
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == '\t') {
            count++;
        }
    }
    return count;
}

int countSentences(const char *text) {
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            count++;
        }
    }
    return count;
}

int countVowels(const char *text) {
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        char ch = tolower(text[i]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }
    return count;
}

void replaceMultipleSpacesWithSingleSpace(char *text) {
    int len = strlen(text);
    int readIndex = 0, writeIndex = 0;
    int spaceFlag = 0;

    while (readIndex < len) {
        if (text[readIndex] == ' ') {
            if (spaceFlag == 0) {
                text[writeIndex] = ' ';
                spaceFlag = 1;
                writeIndex++;
            }
        } else {
            text[writeIndex] = text[readIndex];
            spaceFlag = 0;
            writeIndex++;
        }
        readIndex++;
    }

    text[writeIndex] = '\0';
}

int countParagraphs(const char *text) {
    int count = 0;
    int inParagraph = 0; // A flag to track if we are inside a paragraph.
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == '\n') {
            if (!inParagraph) {
                inParagraph = 1;
                count++;
            }
        } else {
            inParagraph = 0;
        }
    }
    return count;
}

int main() {
    char text[1000];

    printf("Enter a piece of text (max 1000 characters):\n");
    gets(text);

    int choice;
    do {
        printf("\nMENU:\n");
        printf("1. Count the number of spaces\n");
        printf("2. Count the number of tabs\n");
        printf("3. Count the number of sentences\n");
        printf("4. Count the number of vowels\n");
        printf("5. Replace multiple spaces with single space\n");
        printf("6. Count the number of paragraphs\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Number of spaces: %d\n", countSpaces(text));
                break;
            case 2:
                printf("Number of tabs: %d\n", countTabs(text));
                break;
            case 3:
                printf("Number of sentences: %d\n", countSentences(text));
                break;
            case 4:
                printf("Number of vowels: %d\n", countVowels(text));
                break;
            case 5:
                replaceMultipleSpacesWithSingleSpace(text);
                printf("Text with multiple spaces replaced: %s\n", text);
                break;
            case 6:
                printf("Number of paragraphs: %d\n", countParagraphs(text));
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}

