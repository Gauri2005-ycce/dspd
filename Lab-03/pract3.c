#include <stdio.h>
#define MAX 5

char queue[MAX];
int front = -1, rear = -1;

void insert() {
    char ch;
    if (rear == MAX - 1)
        printf("Overflow! Queue is full.\n");
    else {
        printf("Enter character to insert: ");
        scanf(" %c", &ch);
        if (front == -1) front = 0;
        queue[++rear] = ch;
    }
}

void delete() {
    if (front == -1 || front > rear)
        printf("Underflow! Queue is empty.\n");
    else
        printf("Deleted element: %c\n", queue[front++]);
}

void display() {
    int i;
    if (front == -1 || front > rear)
        printf("Queue is empty.\n");
    else {
        printf("Queue elements: ");
        for (i = front; i <= rear; i++)
            printf("%c ", queue[i]);
        printf("\n");
    }
}

int main() {
    int choice;
    do {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: printf("Exiting...\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 4);

    return 0;
}
