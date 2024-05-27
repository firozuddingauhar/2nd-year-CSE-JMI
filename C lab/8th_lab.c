// write a menu driven program in C to newpara a piece of text through keyboard using gets function and perform the following tasks
// count number of spaces , count number of tabs , count number of sentences , count number of vowels , replace multiple spaces with single space , count number of paragraphs
#include <stdio.h>
#include <string.h>
int countSpaces(char text[]) {
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ') {
            count++;
        }
    }
    return count;
}
int countTabs(char text[]){
    int count = 0, i;
    for (i = 0; text[i] != '\0'; i++){
        if (text[i] == '\t'){
            count++;
        }
    }
    return count;
}
int countSentences(char text[]){
    int count = 0, i;
    for (i = 0; text[i] != '\0'; i++){
        if (text[i] == '.' || text[i] == '!' || text[i] == '?'){
            count++;
        }
    }
    return count;
}
int countVowels(char text[]){
    int count = 0, i;
    for (i = 0; text[i] != '\0'; i++){
        if (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u' 
         || text[i] == 'A' || text[i] == 'E' || text[i] == 'I' || text[i] == 'O' || text[i] == 'U'){
            count++;
        }
    }
    return count;
}
int countParagraphs(char text[]){
    int count = 1;
    for (int i = 0; text[i] != '\0'; i++){
        if (text[i] == '\n'){
            count++;
        }
    }
    return count;
}
void replaceSpace(char text[]){
    int i = 0, j = 0, spaceFlag = 0, len = strlen(text);
    while (i < len){
        if (text[i] == ' '){
            if (spaceFlag == 0){
                text[j] = ' ';
                spaceFlag = 1;
                j++;
            }
        }
        else{
            text[j] = text[i];
            spaceFlag = 0;
            j++;
        }
        i++;
    }
    text[j] = '\0';
}
int main()
{
    char text[1000];
    char newpara[1000];
    printf("Enter a piece of text:\n");
    gets(text);
    while (1) {
        gets(newpara);
        if (newpara[0] == '#') {
            break; 
        }
        strcat(text, newpara);
        strcat(text, "\n"); 
    }
    int choice;
    printf("input String :\n%s\n", text);
    printf("\nMENU:\n");
    printf("1. Count the number of spaces\n");
    printf("2. Count the number of tabs\n");
    printf("3. Count the number of sentences\n");
    printf("4. Count the number of vowels\n");
    printf("5. Replace multiple spaces with single space\n");
    printf("6. Count the number of paragraphs\n");
    printf("7. Exit\n");
    while (1){
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 1){
            printf("Number of spaces: %d\n", countSpaces(text));
        }
        else if (choice == 2){
            printf("Number of tabs: %d\n", countTabs(text));
        }
        else if (choice == 3){
            printf("Number of sentences: %d\n", countSentences(text));
        }
        else if (choice == 4){
            printf("Number of vowels: %d\n", countVowels(text));
        }
        else if (choice == 5){
            replaceSpace(text);
            printf("Text with multiple spaces replaced: %s\n", text);
        }
        else if (choice == 6){
            printf("Number of paragraphs: %d\n", countParagraphs(text));
        }
        else if (choice == 7){
            printf("Exiting program.\n");
            break;
        }
        else{
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

// cow is an animal. cow has four legs. it gives us milk.       multiple space. tab