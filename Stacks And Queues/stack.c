#include <stdio.h>
#include <stdlib.h>

// declaring stack
struct node
{
    int data;
    struct node *next;
};

void printStack(struct node *top)
{
    struct node *temp = top;
    while (temp != NULL)
    {
        printf("%d\n|\n", temp->data);
        temp = temp->next;
    }
}


struct node *insertionatbeginning(struct node *top, int data)
{
    struct node *temp = top;
    struct node *nnode = (struct node *)malloc(sizeof(struct node));
    nnode->data = data;
    nnode->next = temp;
    temp = nnode;
    return temp; // new top
}

void  insertionatEnd(struct node *top, int data)
{
    struct node *nnode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = top;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = nnode;
    nnode->data = data;
    nnode->next = NULL;
}

void insertionatSpecificpos(struct node *top, int pos, int data)
{
    struct node *temp = top;
    struct node *nnode = (struct node *)malloc(sizeof(struct node));
    nnode->data = data;
    nnode->next = NULL;
    int i;
    for (i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    nnode->next = temp->next;
    temp->next = nnode;
}

void deletionatpos(struct node* top, struct node* nnode)
{
    struct node *temp;
    int data;
    temp = nnode;
    data = nnode->data;

}


int main()
{
    struct node *nnode, *top, *temp;
    top = NULL;
    int option = 1;
    while (option != 0)
    {
        int data;
        printf("enter data:");
        scanf("%d", &data);
        nnode = (struct node *)malloc(sizeof(struct node));
        if (top == NULL)
        {
            nnode->data = data;
            nnode->next = NULL;
            top = nnode;
        }
        else
        {
            nnode->data = data;
            nnode->next = top;
            top = nnode;
        }
        printf("Do you want to continue:\n");
        printf("enter 1 for yes:\n");
        printf("enter 0 for no\n");
        scanf("%d", &option);
    }
    printf("Stack->\n");
    printStack(top);
    getchar();
    char ch;
    printf("Want to insert data:\n");
    printf("n for no\n");
    scanf(" %c", &ch);
    int data;
    if (ch == 'y' || ch == 'Y')
    {
        printf("where you want to insert data:\n");
        printf("enter b for insertion at beginning\n");
        printf("enter e for insertion at end\n");
        printf("enter i for insertion at specific location\n");
        scanf(" %c", &ch);
        printf("Enter the data you want to insert:\n");
        scanf("%d", &data);
        if (ch == 'b')
        {
            top = insertionatbeginning(top, data);
            printf("Updated stack:\n");
            printStack(top);
        }
        else if (ch == 'e')
        {
            insertionatEnd(top, data);
            printf("Updated stack:\n");
            printStack(top);
        }
        else if (ch == 'i')
        {
            int pos;
            printf("enter the position index:");
            scanf("%d", &pos);
            insertionatSpecificpos(top, pos, data);
            printf("Updated stack:\n");
            printStack(top);
        }
    }
    return 0;
}