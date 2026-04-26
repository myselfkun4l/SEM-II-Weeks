#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack[MAX];
int topArray = -1;

void pushArray(int value) {
    if (topArray == MAX - 1) {
        printf("Stack Overflow (Array)\n");
    } else {
        stack[++topArray] = value;
        printf("%d pushed (Array)\n", value);
    }
}

void popArray() {
    if (topArray == -1) {
        printf("Stack Underflow (Array)\n");
    } else {
        printf("%d popped (Array)\n", stack[topArray--]);
    }
}

void peekArray() {
    if (topArray == -1) {
        printf("Stack is empty (Array)\n");
    } else {
        printf("Top element (Array): %d\n", stack[topArray]);
    }
}

void displayArray() {
    if (topArray == -1) {
        printf("Stack is empty (Array)\n");
    } else {
        printf("Stack elements (Array): ");
        for (int i = topArray; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

struct Node {
    int data;
    struct Node* next;
};

struct Node* topList = NULL;

void pushList(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = topList;
    topList = newNode;
    printf("%d pushed (Linked List)\n", value);
}

void popList() {
    if (topList == NULL) {
        printf("Stack Underflow (Linked List)\n");
    } else {
        struct Node* temp = topList;
        printf("%d popped (Linked List)\n", topList->data);
        topList = topList->next;
        free(temp);
    }
}

void peekList() {
    if (topList == NULL) {
        printf("Stack is empty (Linked List)\n");
    } else {
        printf("Top element (Linked List): %d\n", topList->data);
    }
}

void displayList() {
    if (topList == NULL) {
        printf("Stack is empty (Linked List)\n");
    } else {
        struct Node* temp = topList;
        printf("Stack elements (Linked List): ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice, value, method;

    printf("\nChoose Stack Implementation:\n");
    printf("1. Array\n2. Linked List\n");
    printf("Enter choice: ");
    scanf("%d", &method);

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                if (method == 1) pushArray(value);
                else pushList(value);
                break;
            case 2:
                if (method == 1) popArray();
                else popList();
                break;
            case 3:
                if (method == 1) peekArray();
                else peekList();
                break;
            case 4:
                if (method == 1) displayArray();
                else displayList();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
