#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void enqueue()

void printqueue(struct node *front)
{
    struct node *temp = front;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
}

int main()
{
    struct node *front, *rear, *temp, *nnode;
    front = rear = temp = NULL;
    int option = 1;
    int data;
    // creation of queue
    while (option)
    {
        nnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data:\n");
        scanf("%d", &nnode->data);
        if (front == NULL)
        {
            front = rear = nnode;
            front->next == NULL;
        }
        else
        {
            rear->next = nnode;
            rear = nnode;
            rear->next == NULL;
        }
        printf("Do you want to continue:\n");
        printf("enter 1 for yes\n");
        printf("enter 0 for no\n");
        scanf("%d", &option);
    }
    return 0;
}