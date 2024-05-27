#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    //1
    printf("Hello Students");

    //2
    printf("\nHello\n");
    printf("Students\n");

    //3
    printf("\"MySir\"");

    //4
    double radius, area;
    printf("\n\nEnter the radius of the circle: ");
    scanf("%lf", &radius);
    area = 3.14159265359 * radius * radius;
    printf("Area of circle is %.2lf having the radius %.2lf\n\n", area, radius);

    //5
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    int length = printf("%s", str);
    printf("\nLength of the string is %d\n\n", length);

    //6
    char name[100];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("\"%s\"\n\n", name);

    //7
    printf("%%d\n");

    //8
    printf("\\n\n");

    //9
    printf("\\\\\n");

    //10
    int day, month, year;
    char input[12];
    printf("\nEnter date in format DD/MM/YYYY: ");
    scanf("%s",&input);
    sscanf(input,"%d/%d/%d",&day,&month,&year);
    printf("\"Day-%d, Month-%d, Year-%d\"\n", day, month, year);

    //11
    int hour, minute;
    printf("\nEnter the time in the format 'HHMM' (e.g., 1125): ");
    scanf("%2d%2d", &hour, &minute);
    printf("%d Hour and %d Minute\n\n", hour, minute);
    
    //12
    int x = printf("ineuron");
    printf("%d",x);

}