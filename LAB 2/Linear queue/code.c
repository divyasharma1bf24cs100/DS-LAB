#include<stdio.h>
#define SIZE 5
int queue[SIZE];
int front=-1,rear=-1;
void insert(){
    int item;
    if(rear==SIZE-1){
        printf("Overflow!");
        return;
    }
    else{
        printf("Enter element to be inserted:");
        scanf("%d",&item);
        if(front==-1){
            front=0;
        }
        else{
            rear++;
            queue[rear]=item;
            printf("%d has been inserted",item);
        }
    }
}
void delete(){
    int item;
    if(front==rear||front>rear){
        printf("Underflow!");
        return;
    }
    else{
        printf("%d has been deleted",queue[front]);
        front++;
        if(front>rear){
            front=rear-1;
        }
    }
}
void display(){
    if(front==-1){
        printf("Queue is empty!");
        return;
    }
    else{
        printf("Queue elements are:");
        for(int i=front;i<=rear;i++){
            printf("%d\n",queue[i]);
        }printf("\n");
    }
}
int main(){
    int choice;
    do{
        printf("Linear Queue Operations:");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice){
        case 1: insert();
                break;
        case 2: delete();
                break;
        case 3: display();
                break;
        case 4: printf("Exiting!");
                break;
        default: printf("Invalid choice!");
        }
    }while(choice!=4);
    return 0;
}
