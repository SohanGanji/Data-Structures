#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int main() {
    struct node *head = NULL, *nnode, *tail, *temp;
    int i = 1, count = 0;
    while (i) {
        nnode = (struct node*)malloc(sizeof(struct node));
        count++;
        printf("Enter the data: ");
        scanf("%d", &nnode->data);
        nnode->next = NULL;
        if (head == NULL) {
            head = tail = nnode;
            nnode->next = head;
        } else {
            tail->next = nnode;
            tail = nnode;
            tail->next = head;
        }
        printf("Do you want to continue? Press 1 for yes and 0 for no: ");
        scanf("%d", &i);
    }

    temp = head;
    while(temp != tail){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", tail->data);
    printf("\n");

    int q = 1;
    while (q) {
        int loc;
        printf("Enter the position of the node to be deleted from the circular linked list: ");
        scanf("%d", &loc);

        if (loc > count) {
            printf("This position is not possible!\n");
        } else if (loc == 1) {
            if (head == tail) {
                free(head);
                head = tail = NULL;
            } else {
                temp = head;
                head = head->next;
                tail->next = head;
                free(temp);
            }
        } else if (loc == count) {
            temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            free(tail);
            tail = temp;
            tail->next = head;
        } else {
            temp = head;
            for (i=1;i<loc-1; i++) {
                temp = temp->next;
            }
            struct node* toDelete = temp->next;
            temp->next=toDelete->next;
            free(toDelete);
        }
        count--;

        if (head == NULL) {
            printf("The list is now empty.\n");
        } else {
            temp = head;
            while(temp != tail){
                printf("%d ", temp->data);
                temp = temp->next;
            }
            printf("%d\n", tail->data);
        }
        printf("Do you want to delete another node? Press 1 for yes and 0 for no: ");
        scanf("%d", &q);
    }
    return 0;
}