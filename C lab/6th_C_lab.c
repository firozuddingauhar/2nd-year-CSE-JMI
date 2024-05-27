#include<stdio.h>

int main(){
    int array[] = {0,4,-2,1,8,6};
    int current_min = 1000000 , end_min = 1000000;
    int start , end ;
    for (int i = 0; i < (sizeof(array)/sizeof(int)); i++){
        if (current_min > 0){
            current_min = array[i];
            start = i;
        }
        else{
            current_min += array[i];
        }
        if (end_min > current_min){
            end_min = current_min;
        }
        else{
            end = i;
        }
    }
    if (end_min<0){
        printf("subarray is: ");
        for (int i = start; i < end; i++){
            printf("%d ",array[i]);
        }
    }
    else{
        printf("subarray is %d",end_min);
    }
    printf("\nmin continuos sum is %d\n",end_min);
    current_min = -1000000 , end_min = -1000000;
    for (int i = 0; i < (sizeof(array)/sizeof(int)); i++){
        if (current_min < 0){
            current_min = array[i];
        }
        else{
            current_min += array[i];
        }
        if (end_min < current_min){
            end_min = current_min;
        }
    }
    printf("\nmax continous sum is %d\n",end_min);
}



