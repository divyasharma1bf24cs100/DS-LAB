#include<stdio.h>
#define MAX 5
int stack[MAX];
int top=-1;
void push(int value){
    if(top==MAX-1){
        printf("Overflow!");
    }
    else{
        top++;
        stack[top]=value;
        printf("%d pushed onto stack",value);
    }
}
void pop(){
    if(top==-1){
        printf("Underflow!");
    }
    else{
        printf("%d popped from stack",stack[top]);
        top--;
    }
}
void display(){
    if(top==-1){
        printf("Stack is empty!");
    }
    else{
        printf("Stack elements are:");
        for(int i=top;i>=0;i--){
            printf("%d\n",stack[i]);
        }
    }
}
int main(){
    int choice,value;
    while(1){
        printf("\n____Stack menu____\n");
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice){
        case 1: printf("Enter value to push:");
                scanf("%d",&value);
                push(value);
                break;
        case 2: pop();
                break;
        case 3: display();
                break;
        case 4: printf("Exiting!");
                return 0;;
        default: printf("Invalid choice!");
        }
    }return 0;
}
