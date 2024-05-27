// write a C program to perform the following operations on complex numbers
// 1 addition 2 subtraction 3 multiplication 4 division
// your program should take string as input from user and then convert given string into complex number (eg input "1.5 + 2.3i , 1.55 + 2.0i")
#include <stdio.h>

typedef struct
{
    double real;
    double imag;
} Complex;

void parseComplex(const char *input, Complex *num1, Complex *num2)
{
    int index = 0;
    while (input[index] == ' ' || input[index] == '\t')
    {
        index++;
    }

    sscanf(input + index, "%lf", &num1->real);
    while (input[index] != '+' && input[index] != '-')
    {
        index++;
    }

    sscanf(input + index, "%lfi", &num1->imag);
    while (input[index] != ',')
    {
        index++;
    }

    index++; 

    sscanf(input + index, "%lf", &num2->real);
    while (input[index] != '+' && input[index] != '-')
    {
        index++;
    }

    sscanf(input + index, "%lfi", &num2->imag);

    //
    // float real1 = 0, imag1 = 0, real2 = 0, image2 = 0;
    // int i = 0;
    // while (input[i] != '+' && input[i] != '-')
    // {
    //     i++;
    // }
    // int i1 = i;
    // i--;
    // float k = 0.01;
    // while (0 <= i)
    // {
    //     if (input[i] == '.')
    //         k = 1;
    //     else

    //     {
    //         real1 = real1 + (input[i] - 48) * k;
    //         k = k * 10;
    //     }
    //     i--;
    // }
    // i = i1;
    // while (input[i1] != 'i')
    // {
    //     i1++;
    // }
    // k = 0.01;
    // int i2 = i1;
    // i1--;
    // while (i < i1)
    // {
    //     if (input[i1] == '.')
    //         k = 1;
    //     else
    //     {
    //         imag1 = imag1 + (input[i1] - 48) * k;
    //         k = k * 10;
    //     }
    //     i1--;
    // }
    // i2++;
    // i1 = i2;
    // while (input[i2] != '+')
    //     i2++;
    // i = i2;
    // i2--;
    // k = 0.01;
    // while (i1 < i2)
    // {
    //     if (input[i2] == '.')
    //         k = 1;
    //     else
    //     {
    //         real2 = real2 + (input[i2] - 48) * k;
    //         k = k * 10;
    //     }
    //     i2--;
    // }
    // i2 = i;
    // while (input[i2] != 'i')
    //     i2++;
    // i2--;
    // k = 0.01;

    // while (i < i2)
    // {
    //     if (input[i2] == '.')
    //         k = 1;
    //     else
    //     {
    //         image2 = image2 + (input[i2] - 48) * k;
    //         k = k * 10;
    //     }
    //     i2--;
    // }
}

void addComplex(const Complex *num1, const Complex *num2, Complex *result)
{
    result->real = num1->real + num2->real;
    result->imag = num1->imag + num2->imag;
}

void subtractComplex(const Complex *num1, const Complex *num2, Complex *result)
{
    result->real = num1->real - num2->real;
    result->imag = num1->imag - num2->imag;
}

void multiplyComplex(const Complex *num1, const Complex *num2, Complex *result)
{
    result->real = (num1->real * num2->real) - (num1->imag * num2->imag);
    result->imag = (num1->real * num2->imag) + (num1->imag * num2->real);
}

void divideComplex(const Complex *num1, const Complex *num2, Complex *result)
{
    double denominator = (num2->real * num2->real) + (num2->imag * num2->imag);
    result->real = ((num1->real * num2->real) + (num1->imag * num2->imag)) / denominator;
    result->imag = ((num1->imag * num2->real) - (num1->real * num2->imag)) / denominator;
}

int main()
{
    char input[100];
    int choice;

    Complex num1, num2, result;

    do
    {
        printf("Enter two complex numbers separated by a comma in the format 'a +bi, c +di': ");
        fgets(input, sizeof(input), stdin);

        parseComplex(input, &num1, &num2);

        printf("Complex Number 1: %.2f + %.2fi\n", num1.real, num1.imag);
        printf("Complex Number 2: %.2f + %.2fi\n", num2.real, num2.imag);

        printf("Choose an operation:\n");
        printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit\n");
        scanf("%d", &choice);
        getchar();

        if (choice == 1)
        {
            addComplex(&num1, &num2, &result);
            printf("Addition Result: %.2f + %.2fi\n", result.real, result.imag);
        }
        else if (choice == 2)
        {
            subtractComplex(&num1, &num2, &result);
            printf("Subtraction Result: %.2f + %.2fi\n", result.real, result.imag);
        }
        else if (choice == 3)
        {
            multiplyComplex(&num1, &num2, &result);
            printf("Multiplication Result: %.2f + %.2fi\n", result.real, result.imag);
        }
        else if (choice == 4)
        {
            divideComplex(&num1, &num2, &result);
            printf("Division Result: %.2f + %.2fi\n", result.real, result.imag);
        }
        else if (choice == 5)
        {
            printf("Exiting...\n");
            break;
        }
        else
        {
            printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}
