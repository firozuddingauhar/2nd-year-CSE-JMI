#include<stdio.h>
#include<string.h>
#include<math.h>
void Dec2Hex(int decimal){
    int i = 0 ;
    char hexa[69] , rem;
    while (decimal != 0){
        rem = decimal % 16;
        if (rem < 10){
            rem = rem + 48;
        }
        else{
            rem = rem + 55;
        }
        hexa[i] = rem;
        decimal = decimal / 16;
        i++;
    }
    for ( i = i-1; i >= 0; i--){
        printf("%c",hexa[i]);
    }   
}
void Hex2Dec(char hexa[]){
    int i , rem , size = strlen(hexa);
    int decimal = 0;
    for (i = 0 ; size >= 0 ; i++){
        rem = hexa[size];
        if (rem >= 48 && rem <= 57){
            rem = rem - 48;
        }
        else if (rem >= 65 && rem <= 70)
        {
            rem = rem - 55;
        }
        else if (rem >= 97 && rem <= 102){
            rem = rem - 87;
        }
        decimal = decimal + (rem*pow(16,i));
        size --;
    }
    printf("%d",decimal);
}
int main(){
    int i , choice , decimal, hexa;
    while (1){
        printf("\nenter what you want to do\n");
        printf("1) Decimal to Hexadecimal\n");
        printf("2) Hexadecimal to Decimal\n");
        printf("3) Exit\n");
        scanf("%d",&choice);
        if (choice==1){
            printf("Enter Decimal number to convert : ");
            scanf("%d",&decimal);
            Dec2Hex(decimal);
        }
        if (choice==2){
            printf("Enter Hexadecimal number to convert : ");
            scanf("%X",&hexa);
            printf("%d",hexa);
        }
        if (choice==3){
            break;
        }
    }
    printf("program exited");
}