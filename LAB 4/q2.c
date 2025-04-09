#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head = NULL, *var, *temp, *nnode, *head1 = NULL, *head2 = NULL, *temp1, *temp2, *nnode1, *nnode2;
    int q = 1;
    while (q)
    {
        nnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &nnode->data);
        nnode->next = NULL;
        if (head == NULL)
        {
            temp = head = nnode;
        }
        else
        {
            temp->next = nnode;
            temp = nnode;
        }
        printf("Do you want to continue? press 1 for yes and 0 for no: ");
        scanf("%d", &q);
    }

    var = head;
    while (var != NULL)
    {
        struct node *next = var->next;

        if ((var->data) % 2 != 0)
        {
            if (head1 == NULL)
            {
                head1 = temp1 = var;
            }
            else
            {
                temp1->next = var;
                temp1 = var;
            }
            temp1->next = NULL;
        }
        else
        {
            if (head2 == NULL)
            {
                head2 = temp2 = var;
            }
            else
            {
                temp2->next = var;
                temp2 = var;
            }
            temp2->next = NULL;
        }

        var = next;
    }

    printf("The linked list containing odd elements is:-\n");
    temp1 = head1;
    while (temp1 != NULL)
    {
        printf("%d ", temp1->data);
        temp1 = temp1->next;
    }
    printf("\n");

    printf("The linked list containing even elements is:-\n");
    temp2 = head2;
    while (temp2 != NULL)
    {
        printf("%d ", temp2->data);
        temp2 = temp2->next;
    }
    return 0;
}