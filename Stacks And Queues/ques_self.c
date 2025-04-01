#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *nnode, *head, *tail;
    head = tail = NULL;
    int option = 1;

    while(option){
    int data;
    printf("Enter the data:");
    scanf("%d", &data);
    nnode = (struct node *)malloc(sizeof(struct node));
    nnode->next = NULL;
    if (head == NULL)
    {
        head = tail = nnode;
        nnode->data = data;
    }
    else
    {
        tail = nnode;
        nnode->data = data;
        nnode->next = NULL;
    }
    printf("enter 1 to continue / 0 to stop:\n");
    scanf("%d",&option);
    }


    return 0;
}