#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
    printf("%d inserted at the beginning.\n", value);
}

// Insert at end
void insertAtEnd(int value) {
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
    printf("%d inserted at the end.\n", value);
}

// Insert at specific position (1-based index)
void insertAtPosition(int value, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }
    if (position == 1) {
        insertAtBeginning(value);
        return;
    }
    struct Node* newNode = createNode(value);
    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("%d inserted at position %d.\n", value, position);
    }
}

// Delete by value
void deleteByValue(int value) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Value %d not found!\n", value);
        return;
    }
    if (prev == NULL) {
        head = temp->next; 
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Value %d deleted.\n", value);
}

// Delete by position
void deleteByPosition(int position) {
    if (head == NULL || position < 1) {
        printf("Invalid position!\n");
        return;
    }
    struct Node* temp = head;
    if (position == 1) {
        head = head->next;
        printf("Node at position 1 deleted.\n");
        free(temp);
        return;
    }
    struct Node* prev = NULL;
    for (int i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }
    prev->next = temp->next;
    printf("Node at position %d deleted.\n", position);
    free(temp);
}

// Search for a value
void search(int value) {
    struct Node* temp = head;
    int position = 1;
    while (temp != NULL) {
        if (temp->data == value) {
            printf("Value %d found at position %d.\n", value, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Value %d not found in the list.\n", value);
}

// Display list
void display() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, position;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at position\n");
        printf("4. Delete by value\n");
        printf("5. Delete by position\n");
        printf("6. Search\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter value and position: ");
                scanf("%d %d", &value, &position);
                insertAtPosition(value, position);
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteByValue(value);
                break;
            case 5:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteByPosition(position);
                break;
            case 6:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
