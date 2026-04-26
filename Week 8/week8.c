#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int frontArray = -1, rearArray = -1;

void enqueueArray(int value) {
    if (rearArray == MAX - 1) {
        printf("Queue Overflow (Array)\n");
    } else {
        if (frontArray == -1) frontArray = 0;
        queue[++rearArray] = value;
        printf("%d enqueued (Array)\n", value);
    }
}

void dequeueArray() {
    if (frontArray == -1 || frontArray > rearArray) {
        printf("Queue Underflow (Array)\n");
    } else {
        printf("%d dequeued (Array)\n", queue[frontArray++]);
    }
}

void displayArray() {
    if (frontArray == -1 || frontArray > rearArray) {
        printf("Queue is empty (Array)\n");
    } else {
        printf("Queue elements (Array): ");
        for (int i = frontArray; i <= rearArray; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

struct Node {
    int data;
    struct Node* next;
};

struct Node* frontList = NULL;
struct Node* rearList = NULL;

void enqueueList(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rearList == NULL) {
        frontList = rearList = newNode;
    } else {
        rearList->next = newNode;
        rearList = newNode;
    }
    printf("%d enqueued (Linked List)\n", value);
}

void dequeueList() {
    if (frontList == NULL) {
        printf("Queue Underflow (Linked List)\n");
    } else {
        struct Node* temp = frontList;
        printf("%d dequeued (Linked List)\n", frontList->data);
        frontList = frontList->next;
        if (frontList == NULL) rearList = NULL;
        free(temp);
    }
}

void displayList() {
    if (frontList == NULL) {
        printf("Queue is empty (Linked List)\n");
    } else {
        struct Node* temp = frontList;
        printf("Queue elements (Linked List): ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main() {
    int choice, value, method;

    printf("\nChoose Queue Implementation:\n");
    printf("1. Array\n2. Linked List\n");
    printf("Enter choice: ");
    scanf("%d", &method);

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                if (method == 1) enqueueArray(value);
                else enqueueList(value);
                break;
            case 2:
                if (method == 1) dequeueArray();
                else dequeueList();
                break;
            case 3:
                if (method == 1) displayArray();
                else displayList();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
