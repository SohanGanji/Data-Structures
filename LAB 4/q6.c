#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *head = NULL;
    struct Node *tail = NULL;
    int data, choice = 1;
    while (choice)
    {
        printf("Enter data: ");
        scanf("%d", &data);

        struct Node *newNode = createNode(data);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        printf("Do you want to add more nodes? (1/0): ");
        scanf("%d", &choice);
    }

    printf("Original list: ");
    printList(head);

    int count = 0;
    struct Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    for (int i = 0; i < count - 1; i++)
    {
        struct Node *current = head;
        for (int j = 0; j < count - i - 1; j++)
        {
            if (current->data > current->next->data)
            {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
            }
            current = current->next;
        }
    }

    printf("Sorted list: ");
    printList(head);

    while (head != NULL)
    {
        struct Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}