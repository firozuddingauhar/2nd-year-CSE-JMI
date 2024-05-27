struct Employee employees[10];

    // //2. Write a function to take input employee data from the user. 
    // printf("Enter data for 10 employees:\n");
    // for (int i = 0; i < 10; i++) {
    //     printf("Employee %d:\n", i + 1);
    //     inputEmployeeData(&employees[i]);
    // }
    
    // //3. Write a function to display employee data.
    // printf("\n Employee data:\n");
    // printf("| %-4s | %-20s | %-10s |\n", "ID", "Name", "Salary");
    // printf("|------|----------------------|------------|\n");
    // for (int i = 0; i < 10; ++i) {
    //     displayEmployee(employees[i]);
    // }
    // printf("\n");

    // //4. Write a function to find the highest salary employee from a given array of 10 employees.
    // struct Employee highestSalaryEmployee = findHighestSalaryEmployee(employees);
    // printf("\nEmployee with the highest salary:\n");
    // printf("| %-4s | %-20s | %-10s |\n", "ID", "Name", "Salary");
    // printf("|------|----------------------|------------|\n");
    // displayEmployee(highestSalaryEmployee);
    // printf("\n");
    
    // //5. Write a function to sort employees according to their salaries
    // sortEmployeesBySalary(employees);
    // printf("\nEmployees sorted by salary:\n");
    // printf("| %-4s | %-20s | %-10s |\n", "ID", "Name", "Salary");
    // printf("|------|----------------------|------------|\n");
    // for (int i = 0; i < 10; ++i) {
    //     displayEmployee(employees[i]);
    // }
    // printf("\n");

    // //6. Write a function to sort employees according to their names
    // sortEmployeesByName(employees);
    // printf("\nEmployees sorted by name:\n");
    // printf("| %-4s | %-20s | %-10s |\n", "ID", "Name", "Salary");
    // printf("|------|----------------------|------------|\n");
    // for (int i = 0; i < 10; ++i) {
    //     displayEmployee(employees[i]);
    // }
    // printf("\n");

    // //7. Write a program to calculate the difference between two time periods.
    // struct Time startTime, endTime, difference;
    // printf("Enter start time (hours minutes seconds): ");
    // scanf("%d %d %d", &startTime.hours, &startTime.minutes, &startTime.seconds);
    // printf("Enter end time (hours minutes seconds): ");
    // scanf("%d %d %d", &endTime.hours, &endTime.minutes, &endTime.seconds);
    // difference = getTimeDifference(startTime, endTime);
    // printf("Time difference: %d hours, %d minutes, %d seconds\n",difference.hours, difference.minutes, difference.seconds);

    // //8. Write a program to store information of 10 students and display them using structure. 
    
    // struct Student students[10];
    // printf("Enter data for 10 students:\n");
    // for (int i = 0; i < 10; ++i) {
    //     printf("Enter data for student %d:\n", i + 1);
    //     printf("Enter Roll Number: ");
    //     scanf("%d", &students[i].rollNo);
    //     printf("Enter Name: ");
    //     scanf("%s", students[i].name);
    // }
    // printf("\nStudent Information:\n");
    // printf("| %-9s | %-20s |\n", "Roll No", "Name");
    // for (int i = 0; i < 10; ++i) {
    //     printf("|-----------|----------------------|\n");
    //     printf("| %-9d | %-20s |\n", students[i].rollNo, students[i].name);

    // }

    // //9. Write a program to store information of n students and display them using structure
    // int n;
    // printf("Enter the number of students: ");
    // scanf("%d", &n);
    // printf("Enter data for %d students:\n", n);
    // for (int i = 0; i < n; ++i) {
    //     printf("Enter data for student %d:\n", i + 1);
    //     printf("Enter Roll Number: ");
    //     scanf("%d", &students[i].rollNo);
    //     printf("Enter Name: ");
    //     scanf("%s", students[i].name);
    // }
    // printf("\nStudent Information:\n");
    // printf("| %-9s | %-20s |\n", "Roll No", "Name");
    // for (int i = 0; i < n; ++i) {
    //     printf("|-----------|----------------------|\n");
    //     printf("| %-9d | %-20s |\n", students[i].rollNo, students[i].name);
    // }