#include <stdio.h>
#include <math.h>

int main() {

    // program which takes the month number as an input and display number of days in that month.
    int month;
    printf("Enter the month number (1-12): ");
    scanf("%d", &month);
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            printf("31 days\n");
            break;
        case 4: case 6: case 9: case 11:
            printf("30 days\n");
            break;
        case 2:
            printf("28 or 29 days (leap year)\n");
            break;
        default:
            printf("Invalid month number\n");
    }printf("\n");
            
            
    //
    double num1, num2, result;
    char op;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    printf("Enter an operator (1.add 2.sub 3.mul 4.div): ");
    scanf(" %d", &op);
    switch (op) {
        case 1:
            result = num1 + num2;
            printf("Result: %.2lf\n", result);
            break;
        case 2:
            result = num1 - num2;
            printf("Result: %.2lf\n", result);
            break;
        case 3:
            result = num1 * num2;
            printf("Result: %.2lf\n", result);
            break;
        case 4:
            if (num2 != 0) {
                result = num1 / num2;
                printf("Result: %.2lf\n", result);
            } else {
                printf("Error: Division by zero\n");
            }
            break;
        default:
            printf("Invalid operator\n");
    }printf("\n");
      
         
    int day;
    printf("Enter the day number (1-7): ");
    scanf("%d", &day);
    switch (day) {
        case 1:
            printf("Happy Sunday!\n");
            break;
        case 2:
            printf("Hello Monday!\n");
            break;
        case 3:
            printf("Good Tuesday!\n");
            break;
        case 4:
            printf("Wonderful Wednesday!\n");
            break;
        case 5:
            printf("Terrific Thursday!\n");
            break;
        case 6:
            printf("Fantastic Friday!\n");
            break;
        case 7:
            printf("Super Saturday!\n");
            break;
        default:
            printf("Invalid day number\n");
    }printf("\n");
     
           
    int a, b, c;
    printf("Enter three side lengths of a triangle: ");
    scanf("%d %d %d", &a, &b, &c);
    if (a + b > c && a + c > b && b + c > a) {
        if (a == b && b == c) {
            printf("Equilateral triangle\n");
        } else if (a == b || b == c || a == c) {
            printf("Isosceles triangle\n");
        } else if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) {
            printf("Right-angled triangle\n");
        } else {
            printf("Scalene triangle\n");
        }
    } else {
        printf("Invalid side lengths for a triangle\n");
    }printf("\n");

 
    int var;
    printf("Enter a variable (1, 2, or 3): ");
    scanf("%d", &var);
    switch (var) {
        case 1:
            printf("Good\n");
            break;
        case 2:
            printf("Better\n");
            break;
        case 3:
            printf("Best\n");
            break;
        default:
            printf("Invalid\n");
    }printf("\n");
      
         
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        printf("%d is a leap year\n", year);
    } else {
        printf("%d is not a leap year\n", year);
    }printf("\n");


    int units;
    double bill = 0;
    printf("Enter the electricity units consumed: ");
    scanf("%d", &units);
    if (units > 0) {
        if (units <= 50) {
            bill = units * 0.50;
        } else if (units <= 150) {
            bill = 50 * 0.50 + (units - 50) * 0.75;
        } else if (units <= 250) {
            bill = 50 * 0.50 + 100 * 0.75 + (units - 150) * 1.20;
        } else {
            bill = 50 * 0.50 + 100 * 0.75 + 100 * 1.20 + (units - 250) * 1.50;
        }
        bill *= 1.20;
        printf("Total electricity bill: Rs. %.2lf\n", bill);
    } else {
        printf("Invalid number of units\n");
    }printf("\n");


    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    switch (num >= 0) {
        case 1:
            printf("Negative of %d is %d\n", num, -num);
            break;
        case 0:
            printf("Positive of %d is %d\n", num, -num);
            break;
    }printf("\n");
       
           
    int evenNum;
    printf("Enter an even number: ");
    scanf("%d", &evenNum);
    if (evenNum % 2 == 0) {
        int nearestOdd;
        switch (evenNum % 4) {
            case 0:
                nearestOdd = evenNum - 1;
                break;
            case 2:
                nearestOdd = evenNum + 1;
                break;
            default:
                nearestOdd = evenNum; 
        }
        printf("The nearest odd number is: %d\n", nearestOdd);
    } else {
        printf("Invalid input, not an even number\n");
    }printf("\n");

        
    double A, B, C;
    printf("Enter the coefficients a, b, and c of the quadratic equation (ax^2 + bx + c = 0):\n ");
    scanf("%lf %lf %lf", &A, &B, &C);
    double discriminant = B * B - 4 * A * C;
    if (discriminant > 0) {
        double root1 = (-B + sqrt(discriminant)) / (2 * A);
        double root2 = (-B - sqrt(discriminant)) / (2 * A);
        printf("Roots are real and different. Root1 = %.2lf, Root2 = %.2lf\n", root1, root2);
    } else if (discriminant == 0) {
        double root = -B / (2 * A);
        printf("Roots are real and the same. Root = %.2lf\n", root);
    } else {
        printf("Roots are complex.\n");
    }

    return 0;
}
