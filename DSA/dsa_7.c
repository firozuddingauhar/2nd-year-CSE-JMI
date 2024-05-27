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

void insertAtBegin() {
    int value;
    printf("Enter value to insert at the beginning: ");
    scanf("%d", &value);
    
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    printf("Inserted %d at the beginning.\n", value);
}

void insertAtEnd() {
    int value;
    printf("Enter value to insert at the end: ");
    scanf("%d", &value);

    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted %d at the end.\n", value);
}

void insertAfter() {
    int key, value;
    printf("Enter the element after which to insert: ");
    scanf("%d", &key);
    printf("Enter value to insert after %d: ", key);
    scanf("%d", &value);

    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            struct Node* newNode = createNode(value);
            newNode->next = temp->next;
            temp->next = newNode;
            printf("Inserted %d after %d.\n", value, key);
            return;
        }
        temp = temp->next;
    }
    printf("Element %d not found in the list.\n", key);
}

void deleteAtBegin() {
    if (head == NULL) {
        printf("List is empty. No element to delete.\n");
    } else {
        struct Node* temp = head;
        head = head->next;
        printf("Deleted %d from the beginning.\n", temp->data);
        free(temp);
    }
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty. No element to delete.\n");
    } else if (head->next == NULL) {
        printf("Deleted %d from the end.\n", head->data);
        free(head);
        head = NULL;
    } else {
        struct Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        printf("Deleted %d from the end.\n", temp->next->data);
        free(temp->next);
        temp->next = NULL;
    }
}

void deleteElement() {
    int key;
    printf("Enter the element to delete: ");
    scanf("%d", &key);

    if (head == NULL) {
        printf("List is empty. No element to delete.\n");
    } else if (head->data == key) {
        struct Node* temp = head;
        head = head->next;
        printf("Deleted %d from the list.\n", temp->data);
        free(temp);
    } else {
        struct Node* prev = NULL;
        struct Node* curr = head;
        while (curr != NULL && curr->data != key) {
            prev = curr;
            curr = curr->next;
        }
        if (curr != NULL) {
            prev->next = curr->next;
            printf("Deleted %d from the list.\n", curr->data);
            free(curr);
        } else {
            printf("Element %d not found in the list.\n", key);
        }
    }
}

void printList() {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        printf("Linked List: ");
        struct Node* temp = head;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice;
    printf("Name: Firoz Uddin Gauhar\n");
    printf("Roll no: 22BCS041\n\n");
    while (1) {
        printf("\n1) Insert at Beginning\n");
        printf("2) Insert at End\n");
        printf("3) Insert after an Element\n");
        printf("4) Delete at Beginning\n");
        printf("5) Delete at End\n");
        printf("6) Delete a specific Element\n");
        printf("7) Print List\n");
        printf("8) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice==1) {
            insertAtBegin();
        }else if (choice==2) {
            insertAtEnd();
        }else if (choice==3) {
            insertAfter();
        }else if (choice==4) {
            deleteAtBegin();
        }else if (choice==5) {
            deleteAtEnd();
        }else if (choice==6) {
            deleteElement();
        }else if (choice==7) {
            printList();
        }else if (choice==8) {
            break;
        }else{
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}