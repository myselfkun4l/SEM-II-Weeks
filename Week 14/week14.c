#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node {
    int key;
    int value;
    struct Node* next;
};

struct Node* table[SIZE];

int hashFunction(int key) {
    return key % SIZE;
}

void insert(int key, int value) {
    int index = hashFunction(key);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = table[index];
    table[index] = newNode;
}

void delete(int key) {
    int index = hashFunction(key);
    struct Node* temp = table[index];
    struct Node* prev = NULL;

    while (temp != NULL) {
        if (temp->key == key) {
            if (prev == NULL)
                table[index] = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

struct Node* search(int key) {
    int index = hashFunction(key);
    struct Node* temp = table[index];

    while (temp != NULL) {
        if (temp->key == key)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        struct Node* temp = table[i];
        while (temp != NULL) {
            printf("(%d,%d) ", temp->key, temp->value);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    for (int i = 0; i < SIZE; i++)
        table[i] = NULL;

    insert(1, 100);
    insert(11, 200);
    insert(21, 300);

    display();

    struct Node* result = search(11);
    if (result)
        printf("Found: %d\n", result->value);
    else
        printf("Not Found\n");

    delete(11);
    display();

    return 0;
}
