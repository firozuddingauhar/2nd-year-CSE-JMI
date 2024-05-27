// write a menu driven C program to perform the following operation on string without using libray functions
// #include <string.h>
// strlen, strrevl, strcmp, strcat, strcpy, check palindrome, find subtring print the position if found
#include <stdio.h>
int stringLength(char *str){
    int length = 0;
    while (str[length] != '\0'){
        length++;
    }
    return length;
}
void stringReverse(char *str){
    int length = stringLength(str);
    for (int i = 0; i < length / 2; i++){
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}
int stringCompare(char *str1, char *str2){
    int i = 0;
    while (str1[i] == str2[i]){
        if (str1[i] == '\0')
            return 0;
        i++;
    }
    return str1[i] - str2[i];
}
void stringConcatenate(char *str1, char *str2){
    int length1 = stringLength(str1);
    int length2 = stringLength(str2);
    for (int i = 0; i < length2; i++){
        str1[length1 + i] = str2[i];
    }
    str1[length1 + length2] = '\0';
}
void stringCopy(char *dest, char *src){
    int i = 0;
    while (src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}
int isPalindrome(char *str){
    int length = stringLength(str);
    for (int i = 0; i < length / 2; i++){
        if (str[i] != str[length - i - 1]){
            return 0;
        }
    }
    return 1;
}
int findSubstring(char *str, char *substring){
    int i, j;
    int str_len = stringLength(str);
    int sub_len = stringLength(substring);
    for (i = 0; i <= str_len - sub_len; i++){
        for (j = 0; j < sub_len; j++){
            if (str[i + j] != substring[j]){
                break;
            }
        }
        if (j == sub_len){
            return i;
        }
    }
    return -1;
}
int main()
{
    int choice = -1;
    char string1[200];
    char string2[200];
    char substring[200];
    printf("\nEnter choice \n1)strlen\n2)strrevl\n3)strcmp\n4)strcat\n5)srtcpy\n6)check palindrome\n7)find substring\n");
    while (choice != 8){
        scanf("%d", &choice);
        if (choice == 1){
            printf("Enter a string: ");
            scanf("%s", string1);
            printf("Length of the string: %d\n", stringLength(string1));
        }
        else if (choice == 2){
            printf("Enter a string: ");
            scanf("%s", string1);
            stringReverse(string1);
            printf("Reversed string: %s\n", string1);
        }
        else if (choice == 3){
            printf("Enter the first string: ");
            scanf("%s", string1);
            printf("Enter the second string: ");
            scanf("%s", string2);
            if (stringCompare(string1, string2) == 0){
                printf("String are equal\n");
            }
            else{
                printf("String are not equal\n");
            }
        }
        else if (choice == 4){
            printf("Enter the first string: ");
            scanf("%s", string1);
            printf("Enter the second string: ");
            scanf("%s", string2);
            stringConcatenate(string1, string2);
            printf("Concatenated string: %s\n", string1);
        }
        else if (choice == 5){
            printf("Enter the source string: ");
            scanf("%s", string1);
            stringCopy(string2, string1);
            printf("Copied string: %s\n", string2);
        }
        else if (choice == 6){
            printf("Enter a string: ");
            scanf("%s", string1);
            if (isPalindrome(string1))
                printf("The string is a palindrome.\n");
            else
                printf("The string is not a palindrome.\n");
        }
        else if (choice == 7){
            printf("Enter a string: ");
            scanf("%s", string1);
            printf("Enter a substring: ");
            scanf("%s", substring);
            int position = findSubstring(string1, substring);
            if (position != -1)
                printf("Substring found at position %d\n", position);
            else
                printf("Substring not found.\n");
        }
    }
}