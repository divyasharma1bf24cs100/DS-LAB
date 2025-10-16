#include<stdio.h>
#define SIZE 5
int queue[SIZE];
int front = -1, rear = -1;

void insert() {
    int item;
    if (rear == SIZE - 1) {
        printf("Overflow!\n");
        return;
    } else {
        printf("Enter element to be inserted: ");
        scanf("%d", &item);
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = item;
        printf("%d has been inserted\n", item);
    }
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Underflow!\n");
        return;
    } else {
        printf("%d has been deleted\n", queue[front]);
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    do {
        printf("\nLinear Queue Operations:\n");
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
