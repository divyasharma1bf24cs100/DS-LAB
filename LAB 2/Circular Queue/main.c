#include<stdio.h>
#define SIZE 5
int queue[SIZE];
int front = -1, rear = -1;

void insert() {
    int item;
    if ((front == 0 && rear == SIZE - 1) || (rear + 1 == front)) {
        printf("Overflow!\n");
        return;
    }
    printf("Enter element to be inserted: ");
    scanf("%d", &item);
    if (front == -1) {
        front = rear = 0;
    }else{
    rear = (rear + 1) % SIZE;}
    queue[rear] = item;
    printf("%d has been inserted\n", item);
    }
}

void delete() {
    if (front == -1) {
        printf("Underflow!\n");
        return;
    } 
    printf("%d has been deleted\n", queue[front]);
    if (front == rear) {
        front = rear = -1;
    }else{
    front = (front + 1) % SIZE;
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    } 
    printf("Queue elements are: ");
    int i = front;
    while(1){
        printf("%d ", queue[i]);
        if(i == rear){
            break;
        }
        i = (i + 1) % SIZE;
    }printf("\n");
}

int main() {
    int choice;
    do {
        printf("\nCircular Queue Operations:\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insert();
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: printf("Exiting!\n");
                    break;
            default:printf("Invalid choice!\n");
        }
    } while (choice != 4);
    return 0;
}
