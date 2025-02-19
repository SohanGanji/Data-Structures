// Reverse Odd Nodes  In a Linklist

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void reverseOddNodes(struct Node** headRef) {
    if (*headRef == NULL || (*headRef)->next == NULL) return;

    struct Node* oddList = NULL;
    struct Node* temp = *headRef;
    int index = 0;

    while (temp && temp->next) {
        struct Node* odd = temp->next;
        temp->next = odd->next;

        odd->next = oddList;
        oddList = odd;

        temp = temp->next;
        index++;
    }

    temp = *headRef;
    while (oddList) {
        struct Node* odd = oddList;
        oddList = oddList->next;

        odd->next = temp->next;
        temp->next = odd;
        
        temp = temp->next->next;
    }
}

void insertEnd(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int main() {
    struct Node* head = NULL;
    
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    insertEnd(&head, 5);
    insertEnd(&head, 6);
    insertEnd(&head, 7);

    printf("Original List:\n");
    printList(head);

    reverseOddNodes(&head);

    printf("\nList After Reversing Odd-Indexed Nodes:\n");
    printList(head);

    return 0;
}
