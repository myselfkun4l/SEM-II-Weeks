#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void create()
{
    int n, i, value;
    struct node *temp, *newnode;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &value);
        newnode->data = value;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
}

void insert_begin()
{
    int value;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    scanf("%d", &value);
    newnode->data = value;
    newnode->next = head;
    head = newnode;
}

void insert_end()
{
    int value;
    struct node *temp = head;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    scanf("%d", &value);
    newnode->data = value;
    newnode->next = NULL;

    if(head == NULL)
    {
        head = newnode;
        return;
    }

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}

void insert_middle()
{
    int pos, value, i;
    struct node *temp = head;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    scanf("%d %d", &pos, &value);

    for(i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL)
        return;

    newnode->data = value;
    newnode->next = temp->next;
    temp->next = newnode;
}

void delete_begin()
{
    if(head == NULL)
        return;

    struct node *temp = head;
    head = head->next;
    free(temp);
}

void delete_end()
{
    if(head == NULL)
        return;

    struct node *temp = head;
    struct node *prev = NULL;

    if(head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

void delete_middle()
{
    int pos, i;
    scanf("%d", &pos);

    if(head == NULL)
        return;

    struct node *temp = head;
    struct node *prev = NULL;

    for(i = 1; i < pos && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

void traverse()
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice;

    while(1)
    {
        printf("1.Create\n2.Insert Begin\n3.Insert Middle\n4.Insert End\n5.Delete Begin\n6.Delete Middle\n7.Delete End\n8.Traverse\n9.Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: create(); break;
            case 2: insert_begin(); break;
            case 3: insert_middle(); break;
            case 4: insert_end(); break;
            case 5: delete_begin(); break;
            case 6: delete_middle(); break;
            case 7: delete_end(); break;
            case 8: traverse(); break;
            case 9: exit(0);
        }
    }

    return 0;
}

