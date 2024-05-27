#include <stdio.h>
#include <string.h>

// 1. Define a structure Employee with member variables id, name, salary
struct Employee {
    int id;
    char name[100];
    float salary;
};

struct Student {
        int rollNo;
        char name[50];
};

struct Time {
    int hours;
    int minutes;
    int seconds;
};

struct Time getTimeDifference(struct Time t1, struct Time t2) {
    struct Time difference;
    int time1Seconds = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    int time2Seconds = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;
    int secondsDifference = time2Seconds - time1Seconds;
    if (secondsDifference < 0) {
        secondsDifference = -secondsDifference;
    }
    difference.hours = secondsDifference / 3600;
    difference.minutes = (secondsDifference % 3600) / 60;
    difference.seconds = (secondsDifference % 3600) % 60;
    return difference;
}

struct Marks {
        int rollNo;
        char name[50];
        float chemMarks;
        float mathsMarks;
        float phyMarks;
};

// Function to take input employee data from the user
void inputEmployeeData(struct Employee* emp) {
    printf("Enter Employee ID: ");
    scanf("%d", &emp->id);
    printf("Enter Employee Name: ");
    scanf(" %s", emp->name);
    printf("Enter Employee Salary: ");
    scanf("%f", &emp->salary);
}

// Function to display employee data
void displayEmployee(struct Employee emp) {
    printf("| %-4d | %-20s | %-10.2f |\n", emp.id, emp.name, emp.salary);
}

// Function to find the highest salary employee from an array of employees
struct Employee findHighestSalaryEmployee(const struct Employee employees[10]) {
    struct Employee highestSalaryEmployee = employees[0];
    for (int i = 1; i < 10; i++) {
        if (employees[i].salary > highestSalaryEmployee.salary) {
            highestSalaryEmployee = employees[i];
        }
    }
    return highestSalaryEmployee;
}

// Function to sort employees according to their salaries
void sortEmployeesBySalary(struct Employee employees[10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (employees[i].salary > employees[j].salary) {
                struct Employee temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }
}

// Function to sort employees according to their names
void sortEmployeesByName(struct Employee employees[10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (strcmp(employees[i].name, employees[j].name) > 0) {
                struct Employee temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }
}

int main() {
    struct Employee employees[10];

    //2. Write a function to take input employee data from the user. 
    printf("Enter data for 10 employees:\n");
    for (int i = 0; i < 10; i++) {
        printf("Employee %d:\n", i + 1);
        inputEmployeeData(&employees[i]);
    }
    
    //3. Write a function to display employee data.
    printf("\n Employee data:\n");
    printf("| %-4s | %-20s | %-10s |\n", "ID", "Name", "Salary");
    printf("|------|----------------------|------------|\n");
    for (int i = 0; i < 10; ++i) {
        displayEmployee(employees[i]);
    }
    printf("\n");

    //4. Write a function to find the highest salary employee from a given array of 10 employees.
    struct Employee highestSalaryEmployee = findHighestSalaryEmployee(employees);
    printf("\nEmployee with the highest salary:\n");
    printf("| %-4s | %-20s | %-10s |\n", "ID", "Name", "Salary");
    printf("|------|----------------------|------------|\n");
    displayEmployee(highestSalaryEmployee);
    printf("\n");
    
    //5. Write a function to sort employees according to their salaries
    sortEmployeesBySalary(employees);
    printf("\nEmployees sorted by salary:\n");
    printf("| %-4s | %-20s | %-10s |\n", "ID", "Name", "Salary");
    printf("|------|----------------------|------------|\n");
    for (int i = 0; i < 10; ++i) {
        displayEmployee(employees[i]);
    }
    printf("\n");

    //6. Write a function to sort employees according to their names
    sortEmployeesByName(employees);
    printf("\nEmployees sorted by name:\n");
    printf("| %-4s | %-20s | %-10s |\n", "ID", "Name", "Salary");
    printf("|------|----------------------|------------|\n");
    for (int i = 0; i < 10; ++i) {
        displayEmployee(employees[i]);
    }
    printf("\n");

    //7. Write a program to calculate the difference between two time periods.
    struct Time startTime, endTime, difference;
    printf("Enter start time (hours minutes seconds): ");
    scanf("%d %d %d", &startTime.hours, &startTime.minutes, &startTime.seconds);
    printf("Enter end time (hours minutes seconds): ");
    scanf("%d %d %d", &endTime.hours, &endTime.minutes, &endTime.seconds);
    difference = getTimeDifference(startTime, endTime);
    printf("Time difference: %d hours, %d minutes, %d seconds\n",difference.hours, difference.minutes, difference.seconds);

    //8. Write a program to store information of 10 students and display them using structure. 
    
    struct Student students[10];
    printf("Enter data for 10 students:\n");
    for (int i = 0; i < 10; ++i) {
        printf("Enter data for student %d:\n", i + 1);
        printf("Enter Roll Number: ");
        scanf("%d", &students[i].rollNo);
        printf("Enter Name: ");
        scanf("%s", students[i].name);
    }
    printf("\nStudent Information:\n");
    printf("| %-9s | %-20s |\n", "Roll No", "Name");
    for (int i = 0; i < 10; ++i) {
        printf("|-----------|----------------------|\n");
        printf("| %-9d | %-20s |\n", students[i].rollNo, students[i].name);

    }

    //9. Write a program to store information of n students and display them using structure
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    printf("Enter data for %d students:\n", n);
    for (int i = 0; i < n; ++i) {
        printf("Enter data for student %d:\n", i + 1);
        printf("Enter Roll Number: ");
        scanf("%d", &students[i].rollNo);
        printf("Enter Name: ");
        scanf("%s", students[i].name);
    }
    printf("\nStudent Information:\n");
    printf("| %-9s | %-20s |\n", "Roll No", "Name");
    for (int i = 0; i < n; ++i) {
        printf("|-----------|----------------------|\n");
        printf("| %-9d | %-20s |\n", students[i].rollNo, students[i].name);
    }

    //10. Write a program to enter the marks of 5 students in Chemistry, Mathematics and Physics
    //using a structure named Marks having elements roll no.. name, chem_marks, maths_marks and 
    //phy_marks and then display the percentage of each student.
    struct Marks studentMarks[5];
    printf("Enter marks for 5 students in Chemistry, Mathematics, and Physics (out of 100):\n");
    for (int i = 0; i < 5; ++i) {
        printf("Enter data for student %d:\n", i + 1);
        printf("Enter Roll Number: ");
        scanf("%d", &studentMarks[i].rollNo);
        printf("Enter Name: ");
        scanf("%s", studentMarks[i].name);
        printf("Enter Chemistry Marks: ");
        scanf("%f", &studentMarks[i].chemMarks);
        printf("Enter Mathematics Marks: ");
        scanf("%f", &studentMarks[i].mathsMarks);
        printf("Enter Physics Marks: ");
        scanf("%f", &studentMarks[i].phyMarks);
    }
    printf("\nStudent Percentage:\n");
    printf("| %-9s | %-20s | %-10s |\n", "Roll No", "Name", "Percentage" );
    for (int i = 0; i < 5; ++i) {
        float totalMarks = studentMarks[i].chemMarks + studentMarks[i].mathsMarks + studentMarks[i].phyMarks;
        float percentage = (totalMarks / 300) * 100;
        printf("|-----------|----------------------|------------|\n");
        printf("| %-9d | %-20s | %-10f |\n", studentMarks[i].rollNo,  studentMarks[i].name, percentage);
    }

    return 0;
}
