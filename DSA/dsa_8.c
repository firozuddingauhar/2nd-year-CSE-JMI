#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int priority;
    struct Node* next;
};

struct Node* front = NULL;

struct Node* createNode(int value, int priority) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

void enqueue() {
    int value, priority;
    printf("Enter value to enqueue: ");
    scanf("%d", &value);
    printf("Enter priority of the value: ");
    scanf("%d", &priority);

    struct Node* newNode = createNode(value, priority);

    if (front == NULL || priority < front->priority) {
        newNode->next = front;
        front = newNode;
    } else {
        struct Node* temp = front;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Enqueued %d with priority %d.\n", value, priority);
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
    } else {
        struct Node* temp = front;
        printf("Dequeued %d with priority %d.\n", temp->data, temp->priority);
        front = front->next;
        free(temp);
    }
}

void isEmpty() {
    if (front == NULL) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue is not empty.\n");
    }
}

void printQueue() {
    if (front == NULL) {
        printf("Queue is empty.\n");
    } else {
        printf("Priority Queue: ");
        struct Node* temp = front;
        while (temp != NULL) {
            printf("(%d, %d) ", temp->data, temp->priority);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    printf("Name: Firoz Uddin Gauhar\n");
    printf("Roll no: 22BCS041\n\n");

    int choice;
    while (1) {
        printf("\n1) Enqueue\n");
        printf("2) Dequeue\n");
        printf("3) IsEmpty\n");
        printf("4) Print Queue\n");
        printf("5) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            enqueue();
        } else if (choice == 2) {
            dequeue();
        } else if (choice == 3) {
            isEmpty();
        } else if (choice == 4) {
            printQueue();
        } else if (choice == 5) {
            printf("Exiting the program.\n");
            break;
        } else {
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
