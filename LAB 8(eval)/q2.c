#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node *head = NULL, *temp = NULL;
    char choice[10];
    int value, k;

    while (1) {
        printf("Enter value: ");
        scanf("%d", &value);

        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }

        printf("Do you want to continue? (yes/no): ");
        scanf("%s", choice);
        if (strcmp(choice, "no") == 0)
            break;
    }

    printf("Enter group size k: ");
    scanf("%d", &k);

    struct Node *curr = head, *newHead = NULL, *prevTail = NULL;

    while (curr != NULL) {
        struct Node *groupStart = curr, *groupPrev = NULL;
        int count = 0;

        while (curr != NULL && count < k) {
            struct Node *nextNode = curr->next;
            curr->next = groupPrev;
            groupPrev = curr;
            curr = nextNode;
            count++;
        }

        if (newHead == NULL)
            newHead = groupPrev;

        if (prevTail != NULL)
            prevTail->next = groupPrev;

        prevTail = groupStart;
    }

    printf("List after reversing in groups of %d:\n", k);
    temp = newHead;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}