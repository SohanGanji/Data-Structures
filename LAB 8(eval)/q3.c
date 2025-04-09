#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top1 = NULL;
struct Node* top2 = NULL;

void push1(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top1;
    top1 = newNode;
}

void push2(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top2;
    top2 = newNode;
}

int pop1() {
    if (top1 == NULL) return -1;
    int val = top1->data;
    struct Node* temp = top1;
    top1 = top1->next;
    free(temp);
    return val;
}

int pop2() {
    if (top2 == NULL) return -1;
    int val = top2->data;
    struct Node* temp = top2;
    top2 = top2->next;
    free(temp);
    return val;
}

void displayStack(struct Node* top) {
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\n1. Push Stack 1\n2. Push Stack 2\n3. Pop Stack 1\n4. Pop Stack 2\n5. Display Stack 1\n6. Display Stack 2\n7. Exit\n");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter value: ");
            scanf("%d", &value);
            push1(value);
        } else if (choice == 2) {
            printf("Enter value: ");
            scanf("%d", &value);
            push2(value);
        } else if (choice == 3) {
            value = pop1();
            if (value == -1) printf("Stack 1 is empty\n");
            else printf("Popped from Stack 1: %d\n", value);
        } else if (choice == 4) {
            value = pop2();
            if (value == -1) printf("Stack 2 is empty\n");
            else printf("Popped from Stack 2: %d\n", value);
        } else if (choice == 5) {
            printf("Stack 1: ");
            displayStack(top1);
        } else if (choice == 6) {
            printf("Stack 2: ");
            displayStack(top2);
        } else if (choice == 7) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}