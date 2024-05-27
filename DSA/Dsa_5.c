#include<stdio.h>

int stack[69],top=-1;

void push(int x){
    top++;
    stack[top]=x;
}
void pop(){
    top--;
}
void peek(){
    printf("item at top is %d\n",stack[top]);
}
int isempty(){
    if(top==-1){
        printf("is empty\n");
    }
    return 0;
}
int isfull(){
    if (top>=69){
        printf("is full");
    }
    return 0;
}
void printStack() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack contents:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}
int main()
{
    printf("Name: Firoz Uddin Gauhar\n");
    printf("Roll no: 22BCS041\n\n");
    int item,choice=0;
    while (choice!=7){
        printf("enter choice\n");
        printf("1) push ");
        printf("2) pop ");
        printf("3) peek ");
        printf("4) isempty ");
        printf("5) isfull ");
        printf("6) print stack ");

        scanf("%d",&choice);
        if (choice==1){
            if (!isfull()){
                printf("enter item to push\n");
                scanf("%d",&item);
                push(item);
            }
            else{
                printf("overflow\n");
            }
        }
        if (choice==2){
            if (!isempty()){
                pop();
                printf("Poped\n");
            }
        }
        if (choice==3){
            peek();
        }
        if (choice==4){
            isempty();
        }
        if (choice==5){
            isfull();
        }
        if (choice==6){
            printStack();
        }
    }
}