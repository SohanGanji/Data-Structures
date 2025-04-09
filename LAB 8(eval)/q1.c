#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, digit;
    struct Node *num1 = NULL, *num2 = NULL, *sum = NULL;
    struct Node *temp1 = NULL, *temp2 = NULL, *tempSum = NULL;

    printf("Enter number of digits: ");
    scanf("%d", &n);

    printf("Enter digits of first number (from left to right): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &digit);
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->data = digit;
        newNode->next = NULL;

        if (num1 == NULL) {
            num1 = newNode;
            temp1 = newNode;
        } else {
            temp1->next = newNode;
            temp1 = temp1->next;
        }
    }

    printf("Enter digits of second number (from left to right): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &digit);
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->data = digit;
        newNode->next = NULL;

        if (num2 == NULL) {
            num2 = newNode;
            temp2 = newNode;
        } else {
            temp2->next = newNode;
            temp2 = temp2->next;
        }
    }

    struct Node *ptr1 = num1, *ptr2 = num2;

    while (ptr1 != NULL && ptr2 != NULL) {
        int total = ptr1->data + ptr2->data;
        struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
        newNode->data = total;
        newNode->next = NULL;

        if (sum == NULL) {
            sum = newNode;
            tempSum = newNode;
        } else {
            tempSum->next = newNode;
            tempSum = tempSum->next;
        }

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    printf("Resultant sum: ");
    struct Node* temp = sum;
    while (temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}
