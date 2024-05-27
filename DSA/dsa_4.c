#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
    char name[20];
    int roll_no;
    int marks;
} stu;

int main()
{
    printf("Name: Firoz Uddin Gauhar\n");
    printf("Roll no: 22BCS041\n\n");
    int n=0, i, rollserch, choice, lessthanmarks;
    char nameserch[69];
    stu *ptr;
    ptr = (stu *)malloc(50 * sizeof(stu));
    while (choice!=7)
    {
        printf("\nEnter choice\n");
        printf("1) Add one record\n");
        printf("2) display all\n");
        printf("3) serch by roll\n");
        printf("4) serch by name\n");
        printf("5) topper detail\n");
        printf("6) Students with marks less than input\n");
        printf("7) Exict\n");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("\nEnter name, roll and marks of a student : ");
            scanf("%s %d %d", (ptr + n)->name, &(ptr + n)->roll_no, &(ptr + n)->marks);
            n++;
        }
        if (choice == 2)
        {
            printf("\nDisplaying Information:\n");
            printf("Name\trollno\tmarks\n");
            for (i = 0; i < n; ++i)
            {
                printf("\n%s\t%d\t%d\n", (ptr + i)->name, (ptr + i)->roll_no, (ptr + i)->marks);
            }
            if(n==0){
                printf("\n\tNO RECORDS\n");
            }
        }
        if (choice == 5)
        {
            printf("\nPrinting topper\n");
            int max = 0, key;
            for (i = 0; i < n; i++)
            {
                if ((ptr + i)->marks > max)
                {
                    max = (ptr + i)->marks;
                    key = i;
                }
            }
            printf("%s is the topper roll no %d with %d marks\n", (ptr + key)->name, (ptr + key)->roll_no, (ptr + key)->marks);
        }
        if (choice == 3)
        {
            printf("\nEnter roll to serch\n");
            scanf("%d", &rollserch);
            for (i = 0; i < n; i++)
            {
                if (rollserch == (ptr + i)->roll_no)
                {
                    printf("target student is\n%s with marks%d", (ptr + i)->name, (ptr + i)->marks);
                    break;
                }
            }
        }
        if (choice == 4)
        {
            printf("\nEnter name to serch\n");
            scanf("%s", &nameserch);
            for (i = 0; i < n; i++)
            {
                if (strcmp(nameserch, (ptr + i)->name) == 0)
                {
                    printf("target student is\n %s with marks %d",(ptr + i)->name, (ptr + i)->roll_no);
                    break;
                }
            }
        }
        if (choice == 6)
        {
            printf("\nEnter cutoff to marks\n");
            scanf("%d", &lessthanmarks);
            for (i = 0; i < n; i++)
            {
                if (lessthanmarks > (ptr + i)->marks)
                {
                    printf("Student with marks less than %d are\n%s\t%d", lessthanmarks,(ptr + i)->name, (ptr + i)->roll_no);
                }
            }
        }
    }
}