#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head = NULL, *temp, *newNode;
    int choice = 1;

    while (choice)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL)
        {
            head = temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }

        printf("Do you want to continue? (1 for yes, 0 for no): ");
        scanf("%d", &choice);
    }

    int length = 0;
    temp = head;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }

    printf("The length of the linked list is: %d\n", length);

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}