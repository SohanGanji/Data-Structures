#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int main() {
    struct node *head1 = NULL, *tail1 = NULL;
    struct node *head2 = NULL, *tail2 = NULL;
    struct node *mergedHead = NULL, *mergedTail = NULL;
    struct node *nnode, *temp;
    int i, data;

    printf("Creating the first sorted circular linked list:\n");
    i = 1;
    while (i) {
        nnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for the first list (in ascending order): ");
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

    printf("Creating the second sorted circular linked list:\n");
    i = 1;
    while (i) {
        nnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for the second list (in ascending order): ");
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

    printf("First Sorted Circular Linked List: ");
    temp = head1;
    if (temp != NULL) {
        while (temp->next != head1) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d ", temp->data);
    }
    printf("\n");

    printf("Second Sorted Circular Linked List: ");
    temp = head2;
    if (temp != NULL) {
        while (temp->next != head2) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d ", temp->data);
    }
    printf("\n");

    struct node *p1 = head1, *p2 = head2;
    while (p1->next != head1 && p2->next != head2) {
        if (p1->data <= p2->data) {
            if (mergedHead == NULL) {
                mergedHead = mergedTail = p1;
            } else {
                mergedTail->next = p1;
                mergedTail = p1;
            }
            p1 = p1->next;
        } else {
            if (mergedHead == NULL) {
                mergedHead = mergedTail = p2;
            } else {
                mergedTail->next = p2;
                mergedTail = p2;
            }
            p2 = p2->next;
        }
    }

    while (p1->next != head1) {
        mergedTail->next = p1;
        mergedTail = p1;
        p1 = p1->next;
    }

    while (p2->next != head2) {
        mergedTail->next = p2;
        mergedTail = p2;
        p2 = p2->next;
    }

    if (p1->data <= p2->data) {
        mergedTail->next = p1;
        mergedTail = p1;
        mergedTail->next = p2;
        mergedTail = p2;
    } else {
        mergedTail->next = p2;
        mergedTail = p2;
        mergedTail->next = p1;
        mergedTail = p1;
    }

    mergedTail->next = mergedHead;

    printf("Merged Sorted Circular Linked List: ");
    temp = mergedHead;
    if (temp != NULL) {
        while (temp->next != mergedHead) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d ", temp->data);
    }
    printf("\n");

    return 0;
}
