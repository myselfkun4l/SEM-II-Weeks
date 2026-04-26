#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertNode(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        head->next = head; 
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    printf("Inserted %d\n", value);
}

void deleteNode(int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *current = head, *prev = NULL;

    if (head->data == value) {
        if (head->next == head) { 
            free(head);
            head = NULL;
        } else {
            struct Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            struct Node* toDelete = head;
            head = head->next;
            free(toDelete);
        }
        printf("Deleted %d\n", value);
        return;
    }

    do {
        prev = current;
        current = current->next;
        if (current->data == value) {
            prev->next = current->next;
            free(current);
            printf("Deleted %d\n", value);
            return;
        }
    } while (current != head);

    printf("Value %d not found.\n", value);
}

void traverseList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\n--- Circular Linked List Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertNode(value);
                break;
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;
            case 3:
                traverseList();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
