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

struct Node* reverseOddPositionedNodes(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct Node *oddHead = NULL, *oddTail = NULL;
    struct Node *evenHead = NULL, *evenTail = NULL;
    struct Node *curr = head;
    int index = 1;
    while (curr != NULL) {
        struct Node* next = curr->next;
        if (index % 2 == 1) {
            curr->next = oddHead;
            oddHead = curr;
            if (oddTail == NULL) {
                oddTail = curr;
            }
        } else {
            if (evenHead == NULL) {
                evenHead = curr;
                evenTail = curr;
            } else {
                evenTail->next = curr;
                evenTail = curr;
            }
        }
        curr = next;
        index++;
    }
    if (evenTail != NULL) {
        evenTail->next = NULL;
    }
    struct Node* newHead = NULL;
    struct Node* tail = NULL;
    curr = head;
    index = 1;
    while (oddHead != NULL || evenHead != NULL) {
        if (index % 2 == 1 && oddHead != NULL) {
            if (newHead == NULL) {
                newHead = oddHead;
                tail = oddHead;
                oddHead = oddHead->next;
            } else {
                tail->next = oddHead;
                tail = oddHead;
                oddHead = oddHead->next;
            }
        } else if (index % 2 == 0 && evenHead != NULL) {
            if (tail == NULL) {
                newHead = evenHead;
                tail = evenHead;
                evenHead = evenHead->next;
            } else {
                tail->next = evenHead;
                tail = evenHead;
                evenHead = evenHead->next;
            }
        }
        index++;
    }
    if (tail != NULL) {
        tail->next = NULL;
    }
    return newHead;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* temp = NULL;
    int data;
    printf("Enter data for the nodes (enter -1 to stop):\n"); 
    while (1) {
        printf("Enter data: ");
        scanf("%d", &data);
        if (data == -1) {
            break;
        }
        struct Node* newNode = createNode(data);
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    printf("Original list:-\n");
    printList(head);
    head = reverseOddPositionedNodes(head);
    printf("List after reversing odd positioned nodes:-\n");
    printList(head);
    return 0;
}
