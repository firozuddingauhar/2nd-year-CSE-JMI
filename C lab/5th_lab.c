#include<stdio.h>

int main(){
    int i,j,choice,percent[5],maxper=0,maxs1=0,maxs2=0,maxs3=0,key=0,array[5][5]=  {{1,10,20,30,40},
                                                                                    {2,20,75,33,92},
                                                                                    {3,20,68,60,95},
                                                                                    {4,19,65,49,83},
                                                                                    {5,21,68,60,95}};

    printf("Rollno\tAge\tsub1\tsub2\tsub3\n\n");
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            printf("%d\t",array[i][j]);
        }
        printf("\n\n");
    }
    while (1){
        printf("\n1) Display percentage of each student\n");
        printf("2) Display roll no of student with highest marks in each subject\n");
        printf("3) Display highest percent sudent\n");
        printf("4) Exit\n");
        scanf("%d",&choice);
        if (choice==1){
            for(i=0;i<5;i++){
                percent[i]=(array[i][2]+array[i][3]+array[i][4])/3;
                printf("percentage of student %d is : %d\n",i+1,percent[i]);
            }
        }
        if (choice==2){
            for(i=0;i<5;i++){
                if (maxs1<array[i][2]){
                    maxs1=array[i][2];
                    key=i;
                }
            }
            printf("roll %d got highest marks in sub1 which %d\n",key+1,maxs1);
            for(i=0;i<5;i++){
                if (maxs2<array[i][3]){
                    maxs2=array[i][3];
                    key=i;
                }
            }
            printf("roll %d got highest marks in sub2 which %d\n",key+1,maxs2);
            for(i=0;i<5;i++){
                if (maxs3<array[i][4]){
                    maxs3=array[i][4];
                    key=i;
                }
            }
            printf("roll %d got highest marks in sub3 which %d\n",key+1,maxs3);
        }
        if (choice==3){
            for(i=0;i<5;i++){
                if (maxper<percent[i]){
                    maxper=percent[i];
                    key=i;
                }
            }
            for(i=0;i<5;i++){
                if (maxper==percent[i]&&array[i][1]<array[key][1]){
                    printf("\nstudent with highest percent is roll no %d with %d \n",i+1,maxper);
                    break;
                }
                else if (maxper==percent[i]&&array[i][1]>array[key][1]){
                    printf("\nstudent with highest percent is roll no %d with %d \n",key+1,maxper);
                    break;
                }
                else if (maxper==percent[i]&&array[i][1]==array[key][1]){
                    printf("\nstudent with highest percent is roll no %d with %d \n",key+1,maxper);
                    break;
                }
            }
        }
        if (choice==4){
            break;
        }
    }
}