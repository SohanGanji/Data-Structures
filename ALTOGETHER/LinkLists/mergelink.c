//Assume there are 2 sorted linklists  derive anither linklist using both other linklists and it must be sorted also

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

struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    struct Node* mergedList = NULL;
    
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    
    if (list1->data < list2->data) {
        mergedList = list1;
        list1 = list1->next;
    } else {
        mergedList = list2;
        list2 = list2->next;
    }
    
    struct Node* current = mergedList;
    
    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }
    
    if (list1 != NULL) {
        current->next = list1;
    } else {
        current->next = list2;
    }
    
    return mergedList;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* mergedList = NULL;
    
    append(&list1, 1);
    append(&list1, 3);
    append(&list1, 5);
    append(&list1, 7);
    
    append(&list2, 2);
    append(&list2, 4);
    append(&list2, 6);
    append(&list2, 8);
    
    printf("List 1: ");
    printList(list1);
    
    printf("List 2: ");
    printList(list2);
    
    mergedList = mergeSortedLists(list1, list2);
    
    printf("Merged Sorted List: ");
    printList(mergedList);
    
    return 0;
}
