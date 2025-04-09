#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int main() {
    struct node *head1 = NULL, *tail1 = NULL;
    struct node *head2 = NULL, *tail2 = NULL;
    struct node *nnode, *temp;
    int i, data;

    printf("Creating the first circular linked list:\n");
    i = 1;
    while (i) {
        nnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for the first list: ");
        scanf("%d", &nnode->data);
        nnode->next = NULL;
        if (head1 == NULL) {
            head1 = tail1 = nnode;
            nnode->next = head1;
        } else {
            tail1->next = nnode;
            tail1 = nnode;
            tail1->next = head1;
        }
        printf("Do you want to continue? (1 for yes, 0 for no): ");
        scanf("%d", &i);
    }

    printf("Creating the second circular linked list:\n");
    i = 1;
    while (i) {
        nnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for the second list: ");
        scanf("%d", &nnode->data);
        nnode->next = NULL;
        if (head2 == NULL) {
            head2 = tail2 = nnode;
            nnode->next = head2;
        } else {
            tail2->next = nnode;
            tail2 = nnode;
            tail2->next = head2;
        }
        printf("Do you want to continue? (1 for yes, 0 for no): ");
        scanf("%d", &i);
    }

    printf("First Circular Linked List: ");
    temp = head1;
    if (temp != NULL) {
        while (temp->next != head1) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d ", temp->data);
    }
    printf("\n");

    printf("Second Circular Linked List: ");
    temp = head2;
    if (temp != NULL) {
        while (temp->next != head2) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d ", temp->data);
    }
    printf("\n");

    if (head1 == NULL) {
        head1 = head2;
        tail1 = tail2;
    } else if (head2 != NULL) {
        tail1->next = head2;
        tail2->next = head1;
        tail1 = tail2;
    }

    printf("Combined Circular Linked List: ");
    temp = head1;
    if (temp != NULL) {
        while (temp->next != head1) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d ", temp->data);
    }
    printf("\n");

    return 0;
}