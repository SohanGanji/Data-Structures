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
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

struct Node* inputList() {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    int data, choice = 1;

    while (choice) {
        printf("Enter data: ");
        scanf("%d", &data);

        struct Node* newNode = createNode(data);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        printf("Do you want to add more nodes? (1/0): ");
        scanf("%d", &choice);
    }

    return head;
}

int main() {
    printf("Enter the first list:\n");
    struct Node* list1 = inputList();

    printf("Enter the second list:\n");
    struct Node* list2 = inputList();

    printf("First list: ");
    printList(list1);

    printf("Second list: ");
    printList(list2);

    struct Node* mergedList = NULL;
    struct Node* current = NULL;

    while (list1 != NULL && list2 != NULL) {
        struct Node* temp;
        if (list1->data <= list2->data) {
            temp = list1;
            list1 = list1->next;
        } else {
            temp = list2;
            list2 = list2->next;
        }
        
        if (mergedList == NULL) {
            mergedList = current = temp;
        } else {
            current->next = temp;
            current = temp;
        }
    }

    if (list1 != NULL) {
        if (mergedList == NULL) {
            mergedList = list1;
        } else {
            current->next = list1;
        }
    }

    if (list2 != NULL) {
        if (mergedList == NULL) {
            mergedList = list2;
        } else {
            current->next = list2;
        }
    }

    printf("Merged and sorted list: ");
    printList(mergedList);

    while (mergedList != NULL) {
        struct Node* temp = mergedList;
        mergedList = mergedList->next;
        free(temp);
    }

    return 0;
}