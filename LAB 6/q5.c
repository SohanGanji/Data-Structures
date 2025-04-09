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
    while(temp!=tail){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("%d ",tail->data);
    printf("\n");

    int q = 1;
    while (q) {
        int loc;
        nnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data for the node to be inserted: ");
        scanf("%d", &nnode->data);
        printf("Enter the position of the node to be inserted in the circular linked list: ");
        scanf("%d", &loc);

        if (loc>count+1) {
            printf("This position is not possible!\n");
        } else if (loc==1) {
            tail = head;
            while (tail->next != head) {
                tail = tail->next;
            }
            tail->next = nnode;
            nnode->next = head;
            head = nnode;
        } else if (loc==count+1) {
            tail = head;
            while (tail->next != head) {
                tail = tail->next;
            }
            tail->next = nnode;
            nnode->next = head;
            tail=nnode;
        } else {
            tail = head;
            int i;
            for (i = 1; i<loc-1; i++) {
                tail = tail->next;
            }
            nnode->next = tail->next;
            tail->next = nnode;
            while(tail->next!=head){
                tail=tail->next;
            }
        }
        count++;

        temp=head;
        while(temp!=tail){
            printf("%d ", temp->data);
            temp=temp->next;
        }
        printf("%d\n",tail->data);

        printf("Do you want to insert another node? Press 1 for yes and 0 for no: ");
        scanf("%d", &q);
    }
    return 0;
}