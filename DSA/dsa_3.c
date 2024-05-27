#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int rollNo;
    float marks;
};

void enterStudentDetails(struct Student students[]) {
    printf("Enter details of 5 students:\n");
    for (int i = 0; i < 5; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll No: ");
        scanf("%d", &students[i].rollNo);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }
}

void displayAllRecords(struct Student students[]) {
    printf("All Student Records:\n");
    printf("-------------------------------------------------\n");
    printf("| %-20s | %-8s | %-5s |\n", "Name", "Roll No", "Marks");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < 5; i++) {
        printf("| %-20s | %-8d | %-5.2f |\n", students[i].name, students[i].rollNo, students[i].marks);
    }
    printf("-------------------------------------------------\n");
}

void searchByRollNo(struct Student students[], int rollNo) {
    int found = 0;
    for (int i = 0; i < 5; i++) {
        if (students[i].rollNo == rollNo) {
            printf("Student found!\n");
            printf("| %-20s | %-8s | %-5s |\n", "Name", "Roll No", "Marks");
            printf("-------------------------------------------------\n");
            printf("| %-20s | %-8d | %-5.2f |\n", students[i].name, students[i].rollNo, students[i].marks);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student with Roll No %d not found.\n", rollNo);
    }
}

void searchByName(struct Student students[], char name[]) {
    int found = 0;
    for (int i = 0; i < 5; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Student found!\n");
            printf("| %-20s | %-8s | %-5s |\n", "Name", "Roll No", "Marks");
            printf("-------------------------------------------------\n");
            printf("| %-20s | %-8d | %-5.2f |\n", students[i].name, students[i].rollNo, students[i].marks);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Student with Name %s not found.\n", name);
    }
}

void displayTopperStudent(struct Student students[]) {
    float maxMarks = 0;
    int index = 0;

    for (int i = 0; i < 5; i++) {
        if (students[i].marks > maxMarks) {
            maxMarks = students[i].marks;
            index = i;
        }
    }
    printf("Topper Student Details:\n");
    printf("| %-20s | %-8s | %-5s |\n", "Name", "Roll No", "Marks");
            printf("-------------------------------------------------\n");
            printf("| %-20s | %-8d | %-5.2f |\n", students[index].name, students[index].rollNo, students[index].marks);
}

int main() {
    struct Student students[5];
    int choice, rollNo;
    char name[50];
    printf("Name: Firoz Uddin Gauhar\n");
    printf("Roll no: 22BCS041\n\n");
    while (1) {
        printf("\n1. Enter 5 student details\n");
        printf("2. Display all records\n");
        printf("3. Search student by Roll no\n");
        printf("4. Search student by Name\n");
        printf("5. Display topper student detail\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            enterStudentDetails(students);
        } else if (choice == 2) {
            displayAllRecords(students);
        } else if (choice == 3) {
            printf("Enter Roll No to search: ");
            scanf("%d", &rollNo);
            searchByRollNo(students, rollNo);
        } else if (choice == 4) {
            printf("Enter Name to search: ");
            scanf("%s", name);
            searchByName(students, name);
        } else if (choice == 5) {
            displayTopperStudent(students);
        } else if (choice == 6) {
            printf("Exiting the program.\n");
            break;
        } else {
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}
