#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtBegin(int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    printf("Inserted %d at the beginning.\n", value);
}

void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    printf("Inserted %d at the end.\n", value);
}

void deleteAtBegin() {
    if (head == NULL) {
        printf("Circular Linked List is empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    struct Node* delNode = head;
    head = head->next;
    temp->next = head;
    free(delNode);
    printf("Deleted element from the beginning.\n");
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("Circular Linked List is empty. Cannot delete.\n");
        return;
    }

    struct Node *prev = NULL, *curr = head;
    while (curr->next != head) {
        prev = curr;
        curr = curr->next;
    }

    if (prev == NULL) {
        free(curr);
        head = NULL;
    } else {
        prev->next = head;
        free(curr);
    }
    printf("Deleted element from the end.\n");
}

void displayList() {
    if (head == NULL) {
        printf("Circular Linked List is empty.\n");
        return;
    }

    printf("Circular Linked List: ");
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int choice, value;

    printf("Name: Firoz Uddin Gauhar\n");
    printf("Roll no: 22BCS041\n\n");

    while (1) {
        printf("\n1) Insert at Beginning\n");
        printf("2) Insert at End\n");
        printf("3) Delete at Beginning\n");
        printf("4) Delete at End\n");
        printf("5) Display List\n");
        printf("6) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

            if (choice==1){
                printf("Enter value to insert at the beginning: ");
                scanf("%d", &value);
                insertAtBegin(value);
            }else if (choice==2){
                printf("Enter value to insert at the end: ");
                scanf("%d", &value);
                insertAtEnd(value);
            }else if (choice==3){
                deleteAtBegin();
            }else if (choice==4){
                deleteAtEnd();
            }else if (choice==5){
                displayList();
            }else if (choice==6){
                printf("Exiting the program.\n");
                break;
            }else{
                printf("Invalid choice. Please enter a valid option.\n");
            }   
    }
    return 0;
}
