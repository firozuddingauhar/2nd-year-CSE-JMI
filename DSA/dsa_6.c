#include <stdio.h>

int queue[10];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == 10 - 1) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("Enqueued element: %d\n", value);
    }
}
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty. Cannot dequeue.\n");
    } else {
        printf("Dequeued element: %d\n", queue[front]);
        front++;
        if (front > rear) {
            front = rear = -1;
        }
    }
}
void isEmpty() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue is not empty.\n");
    }
}
void isFull() {
    if (rear == 10 - 1) {
        printf("Queue is full.\n");
    } else {
        printf("Queue is not full.\n");
    }
}
void printQueue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Elements in the queue are:\n");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
void frontElement() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Front element of the queue: %d\n", queue[front]);
}

int main() {
    int choice, value;
    printf("Name: Firoz Uddin Gauhar\n");
    printf("Roll no: 22BCS041\n\n");
    while (1) {
        printf("\n1) Enqueue\n");
        printf("2) Dequeue\n");
        printf("3) IsEmpty\n");
        printf("4) IsFull\n");
        printf("5) Printing Queue\n");
        printf("6) Front\n");
        printf("7) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
        } else if (choice == 2) {
            dequeue();
        } else if (choice == 3) {
            isEmpty();
        } else if (choice == 4) {
            isFull();
        } else if (choice == 5) {
            printQueue();
        } else if (choice == 6) {
            frontElement();
        } else if (choice == 7) {
            printf("Exiting the program.\n");
            break;
        } else {
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}
