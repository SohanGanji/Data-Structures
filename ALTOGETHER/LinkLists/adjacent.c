//write a function for linklist which will swap two adjacent nodes 

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
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

void swapAdjacentNodes(struct Node** head_ref) {
    if (*head_ref == NULL || (*head_ref)->next == NULL)
        return;
    
    struct Node *prev = NULL, *current = *head_ref;
    
    while (current != NULL && current->next != NULL) {
        struct Node *next_node = current->next;
        current->next = next_node->next;
        next_node->next = current;
        
        if (prev == NULL) {
            *head_ref = next_node;
        } else {
            prev->next = next_node;
        }
        
        prev = current;
        current = current->next;
    }
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    
    printf("Original List: ");
    printList(head);
    
    swapAdjacentNodes(&head);
    
    printf("List after swapping adjacent nodes: ");
    printList(head);
    
    return 0;
}
