// create a linked list and create another linked list from which 1st contains even values and 2nd contains odd values only.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void splitList(Node* head, Node** evenList, Node** oddList) {
    while (head) {
        if (head->data % 2 == 0)
            insert(evenList, head->data);
        else
            insert(oddList, head->data);
        head = head->next;
    }
}

void printList(Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    Node* evenList = NULL;
    Node* oddList = NULL;

    int values[] = {10, 15, 8, 23, 42, 17, 4};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++)
        insert(&head, values[i]);

    printf("Original List: ");
    printList(head);

    splitList(head, &evenList, &oddList);

    printf("Even List: ");
    printList(evenList);

    printf("Odd List: ");
    printList(oddList);

    return 0;
}
