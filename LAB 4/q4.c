#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int main() {
    struct node* head = NULL, *temp, *newNode;
    int choice = 1, count = 0;

    while (choice) {
        newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
        count++;

        printf("Do you want to continue? (1 for yes, 0 for no): ");
        scanf("%d", &choice);
    }

    printf("The length of the linked list is: %d\n", count);

    if (count >= 10) {
        struct node *fast = head, *slow = head;
        
        for (int i = 0; i < 3; i++) {
            if (fast == NULL) break;
            fast = fast->next;
        }
        
        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        
        printf("The third node from last is: %d\n", slow->data);
    } else {
        printf("The list doesn't have at least 10 nodes.\n");
    }

    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
