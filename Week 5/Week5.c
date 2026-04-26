#include <stdio.h>  
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;


void create(int n) {
    struct node *newNode, *temp;
    int data;

    for(int i = 1; i <= n; i++) {
        newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &data);

        newNode->data = data;
        newNode->prev = NULL;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }
}

void insertBeginning(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if(head != NULL)
        head->prev = newNode;

    head = newNode;
}


void insertMiddle(int data, int pos) {
    struct node *temp = head;
    struct node *newNode;

    if(pos == 1) {
        insertBeginning(data);
        return;
    }

    for(int i = 1; i < pos-1 && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL) {
        printf("Invalid Position!\n");
        return;
    }

    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;

    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}


void insertEnd(int data) {
    struct node *temp = head;
    struct node *newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL) {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}


void deleteBeginning() {
    struct node *temp;

    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = head;
    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    free(temp);
}

void deleteMiddle(int pos) {
    struct node *temp = head;

    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if(pos == 1) {
        deleteBeginning();
        return;
    }

    for(int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL) {
        printf("Invalid Position!\n");
        return;
    }

    if(temp->next != NULL)
        temp->next->prev = temp->prev;

    if(temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
}


void deleteEnd() {
    struct node *temp = head;

    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    while(temp->next != NULL)
        temp = temp->next;

    if(temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    free(temp);
}


void traverse() {
    struct node *temp = head;

    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("List: ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int mainChoice, subChoice, data, pos, n;

    while(1) {
        printf("\n--- DOUBLY LINKED LIST ---\n");
        printf("1. Create\n");
        printf("2. Insertion\n");
        printf("3. Deletion\n");
        printf("4. Traversal\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &mainChoice);

        switch(mainChoice) {

            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                create(n);
                break;

            case 2:
                printf("\n--- INSERTION ---\n");
                printf("1. At Beginning\n");
                printf("2. At Middle\n");
                printf("3. At End\n");
                printf("Enter choice: ");
                scanf("%d", &subChoice);

                if(subChoice == 1) {
                    printf("Enter data: ");
                    scanf("%d", &data);
                    insertBeginning(data);
                }
                else if(subChoice == 2) {
                    printf("Enter data and position: ");
                    scanf("%d %d", &data, &pos);
                    insertMiddle(data, pos);
                }
                else if(subChoice == 3) {
                    printf("Enter data: ");
                    scanf("%d", &data);
                    insertEnd(data);
                }
                else {
                    printf("Invalid choice!\n");
                }
                break;

            case 3:
                printf("\n--- DELETION ---\n");
                printf("1. At Beginning\n");
                printf("2. At Middle\n");
                printf("3. At End\n");
                printf("Enter choice: ");
                scanf("%d", &subChoice);

                if(subChoice == 1)
                    deleteBeginning();
                else if(subChoice == 2) {
                    printf("Enter position: ");
                    scanf("%d", &pos);
                    deleteMiddle(pos);
                }
                else if(subChoice == 3)
                    deleteEnd();
                else
                    printf("Invalid choice!\n");
                break;

            case 4:
                traverse();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}
