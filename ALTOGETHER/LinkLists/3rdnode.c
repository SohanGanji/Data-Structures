//Find 3rd Node from the last of an Linklist and assume (n>=10)

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

struct Node* findNthFromLast(struct Node* head, int n) {
    struct Node *main_ptr = head, *ref_ptr = head;
    int count = 0;
    
    if (head != NULL) {
        while (count < n) {
            if (ref_ptr == NULL) {
                return NULL;
            }
            ref_ptr = ref_ptr->next;
            count++;
        }
        
        while (ref_ptr != NULL) {
            main_ptr = main_ptr->next;
            ref_ptr = ref_ptr->next;
        }
    }
    
    return main_ptr;
}

int main() {
    struct Node* head = NULL;
    
    for (int i = 1; i <= 15; i++) {
        append(&head, i);
    }
    
    struct Node* result = findNthFromLast(head, 3);
    if (result != NULL) {
        printf("The 3rd node from the last is: %d\n", result->data);
    } else {
        printf("The list has fewer than 3 nodes.\n");
    }
    
    return 0;
}
