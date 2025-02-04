#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d\n", node->data);
        node = node->next;
    }
}

struct Node* concatenate(struct Node* head1, struct Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;

    return head1;
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    int n = 3; // Size of the first linked list
    int m = 2; // Size of the second linked list

    // Creating the first linked list
    for (int i = 1; i <= n; i++) {
        append(&head1, i);
    }

    // Creating the second linked list
    for (int i = 1; i <= m; i++) {
        append(&head2, i + n);
    }

    printf("First Linked List:\n");
    printList(head1);

    printf("Second Linked List:\n");
    printList(head2);

    struct Node* head3 = concatenate(head1, head2);

    printf("Concatenated Linked List:\n");
    printList(head3);

    return 0;
}
